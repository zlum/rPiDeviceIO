#ifndef MPU9255_GYRO_REG_H
#define MPU9255_GYRO_REG_H

#include <cstdint>

/*-----------------------------------------------------------------------
ADDRESSES
-----------------------------------------------------------------------*/
enum class I2C_Address: uint8_t
{
    MPU9255_GYRO        = 0x68
};

/*-----------------------------------------------------------------------
CONST VALUES
-----------------------------------------------------------------------*/
enum class I2C_Value_CONFIG: uint8_t
{
    LPF_8800            = 0x11, // 8800Hz, 0.64mS delay
    LPF_3600            = 0x10, // 3600Hz, 0.11mS delay
    LPF_250             = 0x00, // 250Hz, 0.97mS delay
    LPF_184             = 0x01, // 184Hz, 2.9mS delay
    LPF_92              = 0x02, // 92Hz, 3.9mS delay
    LPF_41              = 0x03, // 41Hz, 5.9mS delay
    LPF_20              = 0x04, // 20Hz, 9.9mS delay
    LPF_10              = 0x05, // 10Hz, 17.85mS delay
    LPF_5               = 0x06  // 5Hz, 33.48mS delay
};

enum class I2C_Value_GYRO_CONFIG: uint8_t
{
    FSR_250             = 0x00, // +/- 250 degrees per second
    FSR_500             = 0x08, // +/- 500 degrees per second
    FSR_1000            = 0x10, // +/- 1000 degrees per second
    FSR_2000            = 0x18  // +/- 2000 degrees per second
};

/*-----------------------------------------------------------------------
REGISTERS
-----------------------------------------------------------------------*/
enum class I2C_Register: uint8_t
{
    X                   = 0x43,
    Y                   = 0x45,
    Z                   = 0x47,
    OFFSET_X            = 0x13,
    OFFSET_Y            = 0x15,
    OFFSET_Z            = 0x17,
    CONFIG              = 0x1A,
    GYRO_CONFIG         = 0x1B,
    SELF_TEST_X         = 0x00,
    SELF_TEST_Y         = 0x01,
    SELF_TEST_Z         = 0x02
};

#endif // MPU9255_GYRO_REG_H
