#ifndef MPU9255_ACCEL_REG_H
#define MPU9255_ACCEL_REG_H

#include <cstdint>

/*-----------------------------------------------------------------------
ADDRESSES
-----------------------------------------------------------------------*/
enum class I2C_Address: uint8_t
{
    MPU9255_ACCEL       = 0x68
};

/*-----------------------------------------------------------------------
CONST VALUES
-----------------------------------------------------------------------*/
enum class I2C_Value_ACCEL_CONFIG_1: uint8_t
{
    FSR_2               = 0x00, // +/- 2g
    FSR_4               = 0x08, // +/- 4g
    FSR_8               = 0x10, // +/- 8g
    FSR_16              = 0x18  // +/- 16g
};

enum class I2C_Value_ACCEL_CONFIG_2: uint8_t
{
    LPF_1130            = 0x08, // 1130Hz, 0.75mS delay
    LPF_460             = 0x00, // 460Hz, 1.94mS delay
    LPF_184             = 0x01, // 184Hz, 5.80mS delay
    LPF_92              = 0x02, // 92Hz, 7.80mS delay
    LPF_41              = 0x03, // 41Hz, 11.80mS delay
    LPF_20              = 0x04, // 20Hz, 19.80mS delay
    LPF_10              = 0x05, // 10Hz, 35.70mS delay
    LPF_5               = 0x06  // 5Hz, 66.96mS delay
};

/*-----------------------------------------------------------------------
REGISTERS
-----------------------------------------------------------------------*/
enum class I2C_Register: uint8_t
{
    X                   = 0x3B,
    Y                   = 0x3D,
    Z                   = 0x3F,
    OFFSET_X_H          = 0x77,
    OFFSET_X_L          = 0x78,
    OFFSET_Y_H          = 0x7A,
    OFFSET_Y_L          = 0x7B,
    OFFSET_Z_H          = 0x7D,
    OFFSET_Z_L          = 0x7E,
    CONFIG_1            = 0x1C,
    CONFIG_2            = 0x1D,
    ODR_CONTROL         = 0x1E,
    WOM_THRESHOLD       = 0x1F,
    SELF_TEST_X         = 0x0D,
    SELF_TEST_Y         = 0x0E,
    SELF_TEST_Z         = 0x0F,
    INT_CTRL            = 0x69
};

#endif // MPU9255_ACCEL_REG_H
