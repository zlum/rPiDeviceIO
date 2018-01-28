#include "imu.h"

#include "mpu9255/mpu9255.h"

IMU* IMU::create(Device::IMU name)
{
    switch(name)
    {
    case Device::IMU::MPU9255:
        return MPU9255::create();
    default:
        break;
    }

    return nullptr;
}
