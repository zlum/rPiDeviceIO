#include "bmp180_therm.h"

#include "bmp180_therm_reg.h"

#include <unistd.h>

BMP180_Therm::BMP180_Therm():
    I2C(I2C_Address::THERM)
{    
}

BMP180_Therm::~BMP180_Therm()
{
}

uint16_t BMP180_Therm::getRawTemperature()
{
    write<uint8_t>(I2C_Register::CONTROL, I2C_Value_CONTROL::READTEMP);
    usleep(5000);

    return read<uint16_t>(I2C_Register::TEMPDATA);
}
