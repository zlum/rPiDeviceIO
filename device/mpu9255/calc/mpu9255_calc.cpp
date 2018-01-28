#include "mpu9255_calc.h"

#include "imu_types.h"
#include "mpu9255/io/mpu9255_raw.h"

#include <math.h>
#include <utility>

MPU9255_Calc::MPU9255_Calc():
    MPU9255()
{
}

MPU9255_Calc::~MPU9255_Calc()
{
    delete calibration;
}

AccelData MPU9255_Calc::getAccel()
{
    AccelData data;
    MPU9255_AccelRawData raw = getRawAccel();

    //TODO: accel config
    double accelDivider;

//    case MPU9255_ACCELFSR_2:
        accelDivider = 16384.0;

//    case MPU9255_ACCELFSR_4:
//        accelDivider = 8192.0;

//    case MPU9255_ACCELFSR_8:
//        accelDivider = 4096.0;

//    case MPU9255_ACCELFSR_16:
//        accelDivider = 2048.0;

    data.x = raw.x / accelDivider;
    data.y = raw.y / accelDivider;
    data.z = raw.z / accelDivider;

    return std::move(data);
}

GyroData MPU9255_Calc::getGyro()
{
    GyroData data;
    MPU9255_GyroRawData raw = getRawGyro();

    //TODO: Gyro config
    double gyroScale;

//    case FSR_250:
        gyroScale = M_PI / (131.0 * 180.0);

//    case FSR_500:
//        gyroScale = M_PI / (62.5 * 180.0);

//    case FSR_1000:
//        gyroScale = M_PI / (32.8 * 180.0);

//    case FSR_2000:
//        gyroScale = M_PI / (16.4 * 180.0);

    data.x = raw.x * gyroScale;
    data.y = raw.y * gyroScale;
    data.z = raw.z * gyroScale;

    return std::move(data);
}

MagData MPU9255_Calc::getMag()
{
    MagData data;
    MPU9255_MagRawData raw = getRawMag();

    data.x = raw.x * calibration->magScaleX;
    data.y = raw.y * calibration->magScaleY;
    data.z = raw.z * calibration->magScaleZ;

    return std::move(data);
}
