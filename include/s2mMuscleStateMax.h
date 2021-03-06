#ifndef S2MMUSCLESTATEMAX_H
#define S2MMUSCLESTATEMAX_H
#include "biorbdConfig.h"
#include "s2mMuscleState.h"

class BIORBD_API s2mMuscleStateMax : public s2mMuscleState
{
    public:
        s2mMuscleStateMax(const double &e = 0, const double &a = 0);
        virtual ~s2mMuscleStateMax();

    protected:
};

#endif // S2MMUSCLESTATEMAX_H
