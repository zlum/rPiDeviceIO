#ifndef BMP180_TYPES_H
#define BMP180_TYPES_H

#include <cstdint>

/*-----------------------------------------------------------------------
ADDRESSES
-----------------------------------------------------------------------*/
enum class I2C_Address: uint8_t
{
    SDC             = 0x68,
    SDA             = 0x77
};

/*-----------------------------------------------------------------------
CONST VALUES
-----------------------------------------------------------------------*/
enum class I2C_Value: uint8_t
{
    CHIPID          = 0x55,
    SOFTRESET       = 0xB6,
    READTEMP        = 0x2E,
    READPRESSURE    = 0x34
};

/*-----------------------------------------------------------------------
REGISTERS
-----------------------------------------------------------------------*/
enum class I2C_Register: uint8_t
{
    AC1             = 0xAA,  // R   Calibration data (16 bits)
    AC2             = 0xAC,  // R   Calibration data (16 bits)
    AC3             = 0xAE,  // R   Calibration data (16 bits)
    AC4             = 0xB0,  // R   Calibration data (16 bits)
    AC5             = 0xB2,  // R   Calibration data (16 bits)
    AC6             = 0xB4,  // R   Calibration data (16 bits)
    B1              = 0xB6,  // R   Calibration data (16 bits)
    B2              = 0xB8,  // R   Calibration data (16 bits)
    MB              = 0xBA,  // R   Calibration data (16 bits)
    MC              = 0xBC,  // R   Calibration data (16 bits)
    MD              = 0xBE,  // R   Calibration data (16 bits)
    CHIPID          = 0xD0,
    VERSION         = 0xD1,
    SOFTRESET       = 0xE0,
    CONTROL         = 0xF4,
    TEMPDATA        = 0xF6,
    PRESSUREDATA    = 0xF6
};

/*-----------------------------------------------------------------------
MODE SETTINGS
-----------------------------------------------------------------------*/
enum class BMP180_Mode: uint8_t
{
    ULTRALOWPOWER = 0,
    STANDARD      = 1,
    HIGHRES       = 2,
    ULTRAHIGHRES  = 3,
    ADVANCEDRES   = 4
};

/*-----------------------------------------------------------------------
CALIBRATION DATA
-----------------------------------------------------------------------*/
struct BMP180_Calibration
{
    int16_t  ac1;
    int16_t  ac2;
    int16_t  ac3;
    uint16_t ac4;
    uint16_t ac5;
    uint16_t ac6;
    int16_t  b1;
    int16_t  b2;
    int16_t  mb;
    int16_t  mc;
    int16_t  md;
};

#endif // BMP180_TYPES_H
