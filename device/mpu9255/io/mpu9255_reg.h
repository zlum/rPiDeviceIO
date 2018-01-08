#ifndef MPU9255_REG_H
#define MPU9255_REG_H

/*-----------------------------------------------------------------------
ADDRESSES
-----------------------------------------------------------------------*/
enum class I2C_Address: uint8_t
{
    MPU9255             = 0x68
};

/*-----------------------------------------------------------------------
CONST VALUES
-----------------------------------------------------------------------*/
enum class I2C_Value: uint8_t
{
    CHIPID              = 0x73,
    RESET_ALL           = 0x80, //PWR_MGMT_1
    RESET_CLOCK         = 0x01, //PWR_MGMT_1
    TURN_ON_ALL         = 0x00, //PWR_MGMT_2
    DISABLE             = 0x00, //INTERRUPTS
    BYPASS_ENABLE       = 0x02  //INT_PIN_CFG
};

/*-----------------------------------------------------------------------
REGISTERS
-----------------------------------------------------------------------*/
enum class I2C_Register: uint8_t
{
    TEMPDATA            = 0x41,
    CHIPID              = 0x75,
    SMPLRT_DIV          = 0x19, //Sample Rate Divider. Typical values:0x07(125Hz) 1KHz internal sample rate
    CONFIG              = 0x1A, //Low Pass Filter.Typical values:0x06(5Hz)
    SIGNAL_PATH_RESET   = 0x68,
    USER_CTRL           = 0x6A, // Bit 7 enable DMP, bit 3 reset DMP
    PWR_MGMT_1          = 0x6B, // Device defaults to the SLEEP mode
    PWR_MGMT_2          = 0x6C,

    //INTERRUPTS
    INT_PIN_CFG         = 0x37,
    INT_ENABLE          = 0x38,
    INT_STATUS          = 0x3A,

    //FIFO
    FIFO_EN             = 0x23,
    FIFO_COUNT          = 0x72,
    FIFO_R_W            = 0x74,

    //I2C
    I2C_MST_CTRL        = 0x24,
    I2C_SLV0_ADDR       = 0x25,
    I2C_SLV0_REG        = 0x26,
    I2C_SLV0_CTRL       = 0x27,
    I2C_SLV1_ADDR       = 0x28,
    I2C_SLV1_REG        = 0x29,
    I2C_SLV1_CTRL       = 0x2A,
    I2C_SLV2_ADDR       = 0x2B,
    I2C_SLV2_REG        = 0x2C,
    I2C_SLV2_CTRL       = 0x2D,
    I2C_SLV3_ADDR       = 0x2E,
    I2C_SLV3_REG        = 0x2F,
    I2C_SLV3_CTRL       = 0x30,
    I2C_SLV4_ADDR       = 0x31,
    I2C_SLV4_REG        = 0x32,
    I2C_SLV4_DO         = 0x33,
    I2C_SLV4_CTRL       = 0x34,
    I2C_SLV4_DI         = 0x35,
    I2C_MST_STATUS      = 0x36,
    I2C_SLV0_DO         = 0x63,
    I2C_SLV1_DO         = 0x64,
    I2C_SLV2_DO         = 0x65,
    I2C_SLV3_DO         = 0x66,
    I2C_MST_DELAY_CTRL  = 0x67
};

#endif // MPU9255_REG_H
