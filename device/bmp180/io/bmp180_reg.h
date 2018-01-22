#ifndef BMP180_TYPES_H
#define BMP180_TYPES_H

#include <cstdint>

/*-----------------------------------------------------------------------
ADDRESSES
-----------------------------------------------------------------------*/
enum class I2C_Address: uint8_t
{
    BMP180          = 0x77
};

/*-----------------------------------------------------------------------
CONST VALUES
-----------------------------------------------------------------------*/
enum class I2C_Value_CHIPID: uint8_t
{
    CHIPID          = 0x55
};

enum class I2C_Value_SOFTRESET: uint8_t
{
    SOFTRESET       = 0xB6
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
    SOFTRESET       = 0xE0
};

#endif // BMP180_TYPES_H
