#include "bmp180_io.h"

#include "bmp180/bmp180_types.h"
#include "int24.h"

#include <unistd.h>

BMP180_IO::BMP180_IO(const BMP180_Mode& mode):
    I2C(I2C_Register::SDA),
    BMP180_Calc()
{
    if(!initialize(mode))
        throw std::runtime_error("Failed to initialize BMP180");
}

BMP180_IO::~BMP180_IO()
{
}

uint16_t BMP180_IO::getRawTemperature()
{
    write<uint8_t>(I2C_Register::CONTROL, I2C_Value::READTEMP);
    usleep(5000);

    return read<uint16_t>(I2C_Register::TEMPDATA);
}

uint24_t BMP180_IO::getRawPressure()
{
    write<uint8_t>(I2C_Register::CONTROL,
                   int(I2C_Value::READPRESSURE) + (int(mode) << 6));

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

bool BMP180_IO::initialize(const BMP180_Mode& mode)
{
    /* Make sure we have the right device */
    uint8_t id;

    id = read<uint8_t>(I2C_Register::CHIPID);

    if(id != uint8_t(I2C_Value::CHIPID))
    {
        return false;
    }

    /* Set the mode indicator */
    this->mode = mode;

    /* Coefficients need to be read once */
    calibration = getCalibration();

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
