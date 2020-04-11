#ifndef DEVICE_H
#define DEVICE_H

#include "device_list.h"
#include "abstract/bps.h"
#include "abstract/imu.h"

namespace Device
{
    // TODO: pass config
    ::BPS* createBPS(BPS);
    ::IMU* createIMU(IMU);
} // namespace Device

#endif // DEVICE_H
