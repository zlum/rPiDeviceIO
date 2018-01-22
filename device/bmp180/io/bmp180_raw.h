#ifndef BMP180_RAW_H
#define BMP180_RAW_H

#include <cstdint>

/*-----------------------------------------------------------------------
MODE SETTINGS
-----------------------------------------------------------------------*/
enum class BMP180_Mode: uint8_t
{
    ULTRALOWPOWER   = 0,
    STANDARD        = 1,
    HIGHRES         = 2,
    ULTRAHIGHRES    = 3,
    ADVANCEDRES     = 4
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

#endif // BMP180_RAW_H
