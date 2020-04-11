#ifndef MPU9255_H
#define MPU9255_H

#include "abstract/imu.h"

class MPU9255:
        public IMU
{
public:
    static MPU9255* create();
    virtual ~MPU9255() = 0;

    virtual AccelData getAccel() override = 0;
    virtual GyroData getGyro() override = 0;
    virtual MagData getMag() override = 0;
};

inline MPU9255::~MPU9255() = default;

#endif // MPU9255_H
