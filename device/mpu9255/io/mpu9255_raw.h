#ifndef MPU9255_RAW_H
#define MPU9255_RAW_H

#include <cstdint>

/*-----------------------------------------------------------------------
ACCELERATION RAW DATA TYPES
-----------------------------------------------------------------------*/
struct MPU9255_AccelRawData
{
    int16_t x = 0;
    int16_t y = 0;
    int16_t z = 0;
};

/*-----------------------------------------------------------------------
MAGNETOMETER RAW DATA TYPES
-----------------------------------------------------------------------*/
struct MPU9255_MagRawData
{
    int16_t x = 0;
    int16_t y = 0;
    int16_t z = 0;
};

/*-----------------------------------------------------------------------
GYROSCOPE RAW DATA TYPES
-----------------------------------------------------------------------*/
struct MPU9255_GyroRawData
{
    int16_t x = 0;
    int16_t y = 0;
    int16_t z = 0;
};

/*-----------------------------------------------------------------------
MPU9255 CALIBRATION DATA TYPES
-----------------------------------------------------------------------*/
struct MPU9255_Calibration
{
    double magScaleX = 1.0;
    double magScaleY = 1.0;
    double magScaleZ = 1.0;
};

#endif // MPU9255_RAW_H
