#ifndef MPU9255_CALC_H
#define MPU9255_CALC_H

#include "mpu9255/mpu9255.h"

struct MPU9255_Calibration;

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
    virtual AccelData getAccel() override final;
    virtual GyroData getGyro() override final;
    virtual MagData getMag() override final;
    //~MPU9255

protected:
    virtual MPU9255_AccelRawData getRawAccel() = 0;
    virtual MPU9255_GyroRawData getRawGyro() = 0;
    virtual MPU9255_MagRawData getRawMag() = 0;
//    virtual int16_t getRawTemperature() = 0;

protected:
    MPU9255_Calibration* calibration = nullptr;
};

#endif // MPU9255_CALC_H
