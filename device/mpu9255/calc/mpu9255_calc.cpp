#include "mpu9255_calc.h"

#include "mpu9255/io/mpu9255_raw.h"
#include "mpu9255/mpu9255_types.h"

#include <utility>

MPU9255_Calc::MPU9255_Calc():
    MPU9255()
{
}

MPU9255_Calc::~MPU9255_Calc()
{
    delete gyroOffset;
}

MPU9255_AccelData MPU9255_Calc::getAccel()
{
    MPU9255_AccelData data;
    MPU9255_AccelRawData raw = getRawAccel();

    data.x = raw.x / 16384.0;
    data.y = raw.y / 16384.0;
    data.z = raw.z / 16384.0;

    return std::move(data);
}

MPU9255_GyroData MPU9255_Calc::getGyro()
{
    MPU9255_GyroData data;
    MPU9255_GyroRawData raw = getRawGyro();

    data.x = raw.x / 32.8;
    data.y = raw.y / 32.8;
    data.z = raw.z / 32.8;

    return std::move(data);
}

MPU9255_MagData MPU9255_Calc::getMag()
{
    MPU9255_MagData data;
    MPU9255_MagRawData raw = getRawMag();

    data.x = raw.x;
    data.y = raw.y;
    data.z = raw.z;

    return std::move(data);
}
