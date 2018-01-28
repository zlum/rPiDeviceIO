#include "device.h"

BPS* Device::createBPS(Device::BPS name)
{
    return ::BPS::create(name);
}

IMU* Device::createIMU(Device::IMU name)
{
    return ::IMU::create(name);
}
