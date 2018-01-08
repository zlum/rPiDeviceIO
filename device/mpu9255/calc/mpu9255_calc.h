#ifndef MPU9255_CALC_H
#define MPU9255_CALC_H

#include "mpu9255/mpu9255.h"

struct MPU9255_AccelRawData;
struct MPU9255_GyroRawData;
struct MPU9255_MagRawData;

class MPU9255_Calc:
        public MPU9255
{
public:
    explicit MPU9255_Calc();
    virtual ~MPU9255_Calc();

    ///MPU9255
    virtual MPU9255_AccelData getAccel() override final;
    virtual MPU9255_GyroData getGyro() override final;
    virtual MPU9255_MagData getMag() override final;
    //~MPU9255

protected:
    virtual MPU9255_AccelRawData getRawAccel() = 0;
    virtual MPU9255_GyroRawData getRawGyro() = 0;
    virtual MPU9255_MagRawData getRawMag() = 0;
    virtual int16_t getRawTemperature() = 0;

protected:
    MPU9255_AccelRawData* accelOffset = nullptr;
    MPU9255_GyroRawData* gyroOffset = nullptr;
    MPU9255_MagRawData* magOffset = nullptr;
};

#endif // MPU9255_CALC_H
