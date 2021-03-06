#ifndef S2MPATH_H
#define S2MPATH_H

#include "s2mString.h"
#include "biorbdConfig.h"
    
#ifdef _WIN64
    #include <direct.h>
	#include <Windows.h>
	#undef max
#elif _WIN32
    #include <direct.h>
	#include <Windows.h>
	#undef max
#else
    #include <sys/stat.h>
    #include <unistd.h>
#endif 

class BIORBD_API s2mPath : public s2mString
{
public: 
    s2mPath();
    s2mPath(const char *c);
    s2mPath(const s2mString &s);
    s2mPath(const std::basic_string<char> &c);
    ~s2mPath();

    // parser un path en folder, filename,e extension
    static void parseFileName(const s2mString& path, s2mString& folder, s2mString& filename, s2mString& ext);
    void parseFileName();

    // Tests sur les fichiers
    bool isFileExist() const;
    static bool isFileExist(const s2mPath&);
    static bool isFileExist(const s2mString&);
    bool isFolderExist() const;
    static bool isFolderExist(const s2mPath&);
    static bool isFolderExist(const s2mString&);
    void createFolder() const;

    // Ces fonctions sont partielles et ne fonctionnent que dans le cas où il y a un certain tronc commun avec m_path
    void setRelativePath(const s2mString&); // setter le path relatif à un dossier précis
    s2mString getRelativePath() const; // Relative path par rapport au path courant
    s2mString getRelativePath(const s2mString& relPath) const; // relative path par rapport au chemin envoyé
    s2mString getAbsolutePath() const;

    // Accessor
    s2mString folder() const;
    s2mString filename() const;
    s2mString extension() const;
    static const char* getCurrentDir();

protected:
    // Parse appelé durant la liste d'initiation pour s2mString
    static s2mString processInputForS2MSTRINGcstr(const s2mString&);

    s2mString m_path; // Comme il a été envoyé
    s2mString m_filename;
    s2mString m_extension;
};


#endif // S2MPATH_H
