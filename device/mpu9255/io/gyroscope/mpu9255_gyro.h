#ifndef MPU9255_GYRO_H
#define MPU9255_GYRO_H

#include "i2c_prot/i2c.h"

class MPU9255_GyroRawData;

class MPU9255_Gyro:
        public virtual I2C
{
public:
    explicit MPU9255_Gyro();
    virtual ~MPU9255_Gyro();

    virtual MPU9255_GyroRawData getRawGyro();

private:
    bool initialize();
    MPU9255_GyroRawData* accumGyroOffset();
    bool setGyroOffset(MPU9255_GyroRawData* offset);

private:
    MPU9255_GyroRawData* offset = nullptr;
};

#endif // MPU9255_GYRO_H
