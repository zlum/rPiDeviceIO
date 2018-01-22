#ifndef MPU9255_TYPES_H
#define MPU9255_TYPES_H

#include <cstdint>

/*-----------------------------------------------------------------------
ACCELEROMETER DATA TYPES
-----------------------------------------------------------------------*/
struct MPU9255_AccelData
{
    double x = 0;
    double y = 0;
    double z = 0;
};

/*-----------------------------------------------------------------------
MAGNETOMETER DATA TYPES
-----------------------------------------------------------------------*/
struct MPU9255_MagData
{
    double x = 0;
    double y = 0;
    double z = 0;
};

/*-----------------------------------------------------------------------
GYROSCOPE DATA TYPES
-----------------------------------------------------------------------*/
struct MPU9255_GyroData
{
    double x = 0;
    double y = 0;
    double z = 0;
};

#endif // MPU9255_TYPES_H
