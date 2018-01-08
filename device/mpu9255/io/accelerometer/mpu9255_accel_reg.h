#ifndef MPU9255_ACCEL_REG_H
#define MPU9255_ACCEL_REG_H

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
enum class I2C_Value: uint8_t
{
    FS_2                = 0x00, //ACCEL_CONFIG_1
    FS_4                = 0x08, //ACCEL_CONFIG_1
    FS_8                = 0x10, //ACCEL_CONFIG_1
    FS_16               = 0x18, //ACCEL_CONFIG_1
    HZ_1130             = 0x00, //ACCEL_CONFIG_2
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
