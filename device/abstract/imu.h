#ifndef IMU_H
#define IMU_H

#include "device_list.h"
#include "imu_types.h"
#include "unit/accelerometer.h"
#include "unit/gyroscope.h"
#include "unit/magnetometer.h"

// Inertial Measurement Unit

class IMU:
        public Accelerometer<AccelData>,
        public Gyroscope<GyroData>,
        public Magnetometer<MagData>
{
public:
    static IMU* create(Device::IMU name);
    virtual ~IMU() = 0;

    virtual AccelData getAccel() override = 0;
    virtual GyroData getGyro() override = 0;
    virtual MagData getMag() override = 0;
};

inline IMU::~IMU() = default;

#endif // IMU_H
