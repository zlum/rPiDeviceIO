#include "mpu9255_mag.h"

#include "mpu9255_mag_reg.h"
#include "mpu9255/io/mpu9255_raw.h"

#include <unistd.h>

#define USLEEP_TIME 200000

MPU9255_Mag::MPU9255_Mag():
    I2C(I2C_Address::MPU9255_MAG)
{
    if(!initialize())
        throw std::runtime_error("Failed to initialize MPU9255 magnetometer");
}

MPU9255_Mag::~MPU9255_Mag()
{
}

MPU9255_MagRawData MPU9255_Mag::getRawMag()
{
    MPU9255_MagRawData data;

    //NOTE: MODE_SINGLE
//    write<uint8_t>(I2C_Register::CONTROL_1, I2C_Value::MODE_SINGLE);

//    uint8_t stat = 0;

//    while (!(stat & uint8_t(I2C_BitField::DATA_READY)))
//    {
//        usleep(100);
//        stat = read<uint8_t>(I2C_Register::STATUS_1);
//    }

    data.x = read<int16_t>(I2C_Register::X, false);
    data.y = read<int16_t>(I2C_Register::Y, false);
    data.z = read<int16_t>(I2C_Register::Z, false);

    uint8_t status = read<uint8_t>(I2C_Register::STATUS_2);

    if(status & uint8_t(I2C_BitField::OVERFLOW))
        throw std::runtime_error("Failed to read MAG due to sensor overflow");

    if(!(status & uint8_t(I2C_BitField::OUTPUT_MODE)))
        throw std::runtime_error("Failed to read MAG due to bad output settings");

    return std::move(data);
}

bool MPU9255_Mag::initialize()
{
    if(!check()) return false;

    write<uint8_t>(I2C_Register::CONTROL_2, I2C_Value::RESET);
    write<uint8_t>(I2C_Register::CONTROL_1, I2C_Value::MODE_CONT_2);
    usleep(USLEEP_TIME);

    return true;
}

bool MPU9255_Mag::check()
{
    //Make sure we have the right device
    uint8_t id;

    id = read<uint8_t>(I2C_Register::ID);

    if(id != uint8_t(I2C_Value::ID))
    {
        return false;
    }

    return true;
}
