#ifndef MPU9255_MAG_REG_H
#define MPU9255_MAG_REG_H

/*-----------------------------------------------------------------------
ADDRESSES
-----------------------------------------------------------------------*/
enum class I2C_Address: uint8_t
{
    MPU9255_MAG         = 0x0C
};

/*-----------------------------------------------------------------------
CONST VALUES
-----------------------------------------------------------------------*/
enum class I2C_Value: uint8_t
{
    ID                  = 0x48, //MAG_ID
    RESET               = 0x01, //MAG_CONTROL_2
    MODE_SINGLE         = 0x11, //MAG_CONTROL_1
    MODE_CONT_1         = 0x12, //MAG_CONTROL_1
    MODE_CONT_2         = 0x16  //MAG_CONTROL_1
};

/*-----------------------------------------------------------------------
BIT FIELDS
-----------------------------------------------------------------------*/
enum class I2C_BitField: uint8_t
{
    DATA_READY          = 0x01, //STATUS_1
    DATA_OVERRUN        = 0x02, //STATUS_1
    OVERFLOW            = 0x08, //STATUS_2
    OUTPUT_MODE         = 0x10  //STATUS_2
};

/*-----------------------------------------------------------------------
REGISTERS
-----------------------------------------------------------------------*/
enum class I2C_Register: uint8_t
{
    X                   = 0x03,
    Y                   = 0x05,
    Z                   = 0x07,
    SENS_X              = 0x10,
    SENS_Y              = 0x11,
    SENS_Z              = 0x12,
    CONTROL_1           = 0x0A,
    CONTROL_2           = 0x0B,
    SELF_TEST           = 0x0C,
    ID                  = 0x00,
    INFO                = 0x01,
    STATUS_1            = 0x02,
    STATUS_2            = 0x09,
    I2C_DISABLE         = 0x0F
};

#endif // MPU9255_MAG_REG_H
