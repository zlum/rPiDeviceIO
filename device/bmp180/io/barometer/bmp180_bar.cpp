#include "bmp180_bar.h"

#include "bmp180_bar_reg.h"
#include "bmp180/io/bmp180_raw.h"

#include "int24/int24.h"

#include <unistd.h>

BMP180_Bar::BMP180_Bar(const BMP180_Mode& mode):
    I2C(I2C_Address::BAR),
    mode(mode)
{
}

BMP180_Bar::~BMP180_Bar()
{
}

uint24_t BMP180_Bar::getRawPressure()
{
    write<uint8_t>(I2C_Register::CONTROL,
                   uint8_t(I2C_Value_CONTROL::READPRESSURE) + (uint8_t(mode) << 6));

    switch(mode)
    {
    case BMP180_Mode::ULTRALOWPOWER:
        usleep(5000);
        break;
    case BMP180_Mode::STANDARD:
        usleep(8000);
        break;
    case BMP180_Mode::HIGHRES:
        usleep(14000);
        break;
    case BMP180_Mode::ULTRAHIGHRES:
        usleep(26000);
        break;
    case BMP180_Mode::ADVANCEDRES:
        usleep(77000);
        break;
    default:
        usleep(77000);
        break;
    }

    return read<uint24_t>(I2C_Register::PRESSUREDATA) >> (8 - int(mode));
}
