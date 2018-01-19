#include "bmp180_io.h"

#include "bmp180/io/barometer/bmp180_bar.h"
#include "bmp180/io/thermometer/bmp180_therm.h"

#include "bmp180_raw.h"
#include "bmp180_reg.h"

#include "int24.h"

#include <unistd.h>

BMP180_IO::BMP180_IO(const BMP180_Mode& mode):
    I2C(I2C_Address::BMP180),
    BMP180_Calc()
{
    if(!initialize(mode))
        throw std::runtime_error("Failed to initialize BMP180");

    barometer = new BMP180_Bar(mode);
    thermometer = new BMP180_Therm();
}

BMP180_IO::~BMP180_IO()
{
}

uint16_t BMP180_IO::getRawTemperature()
{
    return thermometer->getRawTemperature();
}

uint24_t BMP180_IO::getRawPressure()
{
    return barometer->getRawPressure();
}

bool BMP180_IO::initialize(const BMP180_Mode& mode)
{
    if(!check()) return false;

    /* Set the mode indicator */
    this->mode = mode;

    /* Coefficients need to be read once */
    calibration = getCalibration();

    return true;
}

bool BMP180_IO::check()
{
    /* Make sure we have the right device */
    uint8_t id;

    id = read<uint8_t>(I2C_Register::CHIPID);

    if(id != uint8_t(I2C_Value_CHIPID::CHIPID))
    {
        return false;
    }

    return true;
}

BMP180_Calibration* BMP180_IO::getCalibration()
{
    BMP180_Calibration* calibration = new BMP180_Calibration;

    calibration->ac1 = read<int16_t>(I2C_Register::AC1);
    calibration->ac2 = read<int16_t>(I2C_Register::AC2);
    calibration->ac3 = read<int16_t>(I2C_Register::AC3);
    calibration->ac4 = read<uint16_t>(I2C_Register::AC4);
    calibration->ac5 = read<uint16_t>(I2C_Register::AC5);
    calibration->ac6 = read<uint16_t>(I2C_Register::AC6);
    calibration->b1  = read<int16_t>(I2C_Register::B1);
    calibration->b2  = read<int16_t>(I2C_Register::B2);
    calibration->mb  = read<int16_t>(I2C_Register::MB);
    calibration->mc  = read<int16_t>(I2C_Register::MC);
    calibration->md  = read<int16_t>(I2C_Register::MD);

    return calibration;
}
