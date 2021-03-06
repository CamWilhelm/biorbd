# Include python
find_package(PYTHON3 REQUIRED)
include_directories(${Python3_INCLUDE_DIRS})

find_package(Numpy REQUIRED)
include_directories(${NUMPY_INCLUDES})
if(WIN32)
	link_directories(${Python3_RUNTIME_LIBRARY_DIRS}/libs)
endif()

# Add swig module
set(CMAKE_SWIG_FLAGS "")
set(I_SOURCE_FILE ${PROJECT_NAME}_python.i)

set_property(SOURCE ${I_SOURCE_FILE} PROPERTY CPLUSPLUS ON)
SWIG_ADD_LIBRARY(${PROJECT_NAME} TYPE MODULE LANGUAGE python SOURCES ${I_SOURCE_FILE})
swig_link_libraries(${PROJECT_NAME} ${PROJECT_NAME} ${PYTHON_LIBRARIES} ${NUMPY_LIBRARIES})

# Add headers
target_include_directories(_${PROJECT_NAME} PUBLIC
    ${RBDL_INCLUDE_DIR}
    ${Boost_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIR}
    ${DLIB_INCLUDE_DIR}
    ${NUMPY_INCLUDES}
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
    ${PYTHON_INCLUDE_DIRS}
)

if(APPLE)
    SET_TARGET_PROPERTIES(_${PROJECT_NAME} PROPERTIES SUFFIX ".so" INSTALL_RPATH ${${PROJECT_NAME}_BIN_FOLDER})
    SET_TARGET_PROPERTIES(_${PROJECT_NAME} PROPERTIES INSTALL_RPATH_USE_LINK_PATH TRUE)
    set_property(TARGET _${PROJECT_NAME} APPEND PROPERTY LINK_FLAGS "-flat_namespace -undefined suppress")
else()
    SET_TARGET_PROPERTIES(_${PROJECT_NAME} PROPERTIES INSTALL_RPATH ${${PROJECT_NAME}_BIN_FOLDER})
    SET_TARGET_PROPERTIES(_${PROJECT_NAME} PROPERTIES INSTALL_RPATH_USE_LINK_PATH TRUE)
endif()

# Install to the proper directories
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.py 
        DESTINATION ${Python3_SITELIB}/${PROJECT_NAME}
        RENAME __init__.py)

# Check if swig has its version 3 or 4, to choose the right place to put the library
if(${SWIG_VERSION} MATCHES "^3(\.[0-9]*)*$")
  set(PYTHON_INSTALL_DESTINATION ${Python3_SITELIB})
elseif(${SWIG_VERSION} MATCHES "^4(\.[0-9]*)*$")
  set(PYTHON_INSTALL_DESTINATION ${Python3_SITELIB}/${PROJECT_NAME})
else()
  message( FATAL_ERROR "Swig must be version 3 or 4" )
endif()

# Install the library
INSTALL(TARGETS _${PROJECT_NAME}
                DESTINATION ${PYTHON_INSTALL_DESTINATION})

