#ifndef MPU9255_TYPES_H
#define MPU9255_TYPES_H

#include <cstdint>

/*-----------------------------------------------------------------------
ACCELEROMETER DATA TYPES
-----------------------------------------------------------------------*/
struct MPU9255_AccelData
{
    float x = 0;
    float y = 0;
    float z = 0;
};

/*-----------------------------------------------------------------------
MAGNETOMETER DATA TYPES
-----------------------------------------------------------------------*/
struct MPU9255_MagData
{
    float x = 0;
    float y = 0;
    float z = 0;
};

/*-----------------------------------------------------------------------
GYROSCOPE DATA TYPES
-----------------------------------------------------------------------*/
struct MPU9255_GyroData
{
    float x = 0;
    float y = 0;
    float z = 0;
};

#endif // MPU9255_TYPES_H
