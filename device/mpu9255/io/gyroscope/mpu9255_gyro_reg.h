#ifndef MPU9255_GYRO_REG_H
#define MPU9255_GYRO_REG_H

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
enum class I2C_Value: uint8_t
{
    //Values got +1 to bypass DLPF
    FS_250              = 0x01,
    FS_500              = 0x09,
    FS_1000             = 0x11,
    FS_2000             = 0x19
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
    CONFIG              = 0x1B,
    SELF_TEST_X         = 0x00,
    SELF_TEST_Y         = 0x01,
    SELF_TEST_Z         = 0x02
};

#endif // MPU9255_GYRO_REG_H
