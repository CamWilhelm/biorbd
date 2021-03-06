#ifndef S2MGENCOORD_H
#define S2MGENCOORD_H
	#include <Eigen/Dense>
    #include "biorbdConfig.h"
    #include "s2mQuaternion.h"
    #include "s2mVector.h"
    #include "s2mJoints.h"

class s2mJoints;
class BIORBD_API s2mGenCoord : public s2mVector
{
public:
    s2mGenCoord();
    s2mGenCoord(const s2mGenCoord &Q);
    s2mGenCoord(const s2mVector& v);
    s2mGenCoord(const Eigen::VectorXd& v);
    s2mGenCoord(unsigned int i);
    s2mGenCoord(const s2mJoints& j);

    s2mGenCoord& operator=(const Eigen::VectorXd& vecX);

protected:
private:

};

#endif // S2MGENCOORD_H
