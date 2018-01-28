#ifndef IMU_TYPES_H
#define IMU_TYPES_H

/*-----------------------------------------------------------------------
ACCELEROMETER DATA TYPES
-----------------------------------------------------------------------*/
struct AccelData
{
    double x = 0;
    double y = 0;
    double z = 0;
};

/*-----------------------------------------------------------------------
MAGNETOMETER DATA TYPES
-----------------------------------------------------------------------*/
struct MagData
{
    double x = 0;
    double y = 0;
    double z = 0;
};

/*-----------------------------------------------------------------------
GYROSCOPE DATA TYPES
-----------------------------------------------------------------------*/
struct GyroData
{
    double x = 0;
    double y = 0;
    double z = 0;
};

#endif // IMU_TYPES_H
