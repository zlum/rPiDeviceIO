#ifndef MPU9255_IO_H
#define MPU9255_IO_H

#include "i2c/i2c.h"
#include "mpu9255/calc/mpu9255_calc.h"

class MPU9255_Accel;
class MPU9255_Gyro;
class MPU9255_Mag;

class MPU9255_IO:
        public I2C,
        public MPU9255_Calc
{
public:
    explicit MPU9255_IO();
    virtual ~MPU9255_IO();

    ///MPU9255_Calc
    virtual MPU9255_AccelRawData getRawAccel() override final;
    virtual MPU9255_GyroRawData getRawGyro() override final;
    virtual MPU9255_MagRawData getRawMag() override final;
    virtual int16_t getRawTemperature() override final;
    //~MPU9255_Calc

private:
    bool initialize();
    bool check();

private:
    MPU9255_Accel* accelerometer = nullptr;
    MPU9255_Gyro* gyroscope = nullptr;
    MPU9255_Mag* magnitomter = nullptr;
};

#endif // MPU9255_IO_H
