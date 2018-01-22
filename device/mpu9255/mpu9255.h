#ifndef MPU9255_H
#define MPU9255_H

#include "mpu9255_types.h"

class MPU9255
{
public:
    static MPU9255* create();
    virtual ~MPU9255() = 0;

    virtual MPU9255_AccelData getAccel() = 0;
    virtual MPU9255_GyroData getGyro() = 0;
    virtual MPU9255_MagData getMag() = 0;
};

inline MPU9255::~MPU9255() {}

#endif // MPU9255_H
