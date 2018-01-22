#include "mpu9255_mag.h"

#include "mpu9255_mag_raw.h"
#include "mpu9255_mag_reg.h"
#include "mpu9255/io/mpu9255_raw.h"

#include <unistd.h>

#define USLEEP_TIME 100
#define USLEEP_MAX_COUNT 10000

MPU9255_Mag::MPU9255_Mag():
    I2C(I2C_Address::MPU9255_MAG)
{
    if(!initialize())
        throw std::runtime_error("Failed to initialize MPU9255 magnetometer");
}

MPU9255_Mag::~MPU9255_Mag()
{
    delete adjustment;
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

    if(status & uint8_t(I2C_BitField_STATUS_2::OVERFLOW))
        throw std::runtime_error("Failed to read MAG due to sensor overflow");

    if(!(status & uint8_t(I2C_BitField_STATUS_2::OUTPUT_MODE)))
        throw std::runtime_error("Failed to read MAG due to bad output settings");

    return std::move(data);
}

MPU9255_Calibration* MPU9255_Mag::getCalibration(MPU9255_Calibration* calibration) const
{
    calibration->magScaleX = adjustment->x;
    calibration->magScaleY = adjustment->y;
    calibration->magScaleZ = adjustment->z;

    return calibration;
}

bool MPU9255_Mag::initialize()
{
    if(!check()) return false;
    if(!reboot()) return false;

    adjustment = getAdjustment();

    write<uint8_t>(I2C_Register::CONTROL_1, I2C_Value_MAG_CONTROL_1::MEAS_CONT_2);

    // Waiting for data
    uint16_t i = 0;

    while(!(read<uint8_t>(I2C_Register::STATUS_1) & uint8_t(I2C_BitField_STATUS_1::DATA_OVERRUN)))
    {
        if(i++ > USLEEP_MAX_COUNT) return false;
        usleep(USLEEP_TIME);
    }

    return true;
}

bool MPU9255_Mag::check()
{
    // Make sure we have the right device
    uint8_t id;

    id = read<uint8_t>(I2C_Register::ID);

    if(id != uint8_t(I2C_Value_ID::ID))
    {
        return false;
    }

    return true;
}

bool MPU9255_Mag::reboot()
{
    write<uint8_t>(I2C_Register::CONTROL_2, I2C_Value_MAG_CONTROL_2::RESET);

    // Waiting for reboot
    uint16_t i = 0;

    while(read<uint8_t>(I2C_Register::CONTROL_2) & uint8_t(I2C_BitField_CONTROL_2::RESET))
    {
        if(i++ > USLEEP_MAX_COUNT) return false;
        usleep(USLEEP_TIME);
    }

    return true;
}

MPU9255_MagAdjustment* MPU9255_Mag::getAdjustment()
{
    MPU9255_MagAdjustment* adjust = new MPU9255_MagAdjustment;

    write<uint8_t>(I2C_Register::CONTROL_1, I2C_Value_MAG_CONTROL_1::FUSE_ROM_ACCESS);

    uint8_t asaX = read<uint8_t>(I2C_Register::ASA_X);
    uint8_t asaY = read<uint8_t>(I2C_Register::ASA_Y);
    uint8_t asaZ = read<uint8_t>(I2C_Register::ASA_Z);

    // Convert asa to usable scale factor
    adjust->x = (double(asaX) - 128.0) / 256.0 + 1.0;
    adjust->y = (double(asaY) - 128.0) / 256.0 + 1.0;
    adjust->z = (double(asaZ) - 128.0) / 256.0 + 1.0;

    return adjust;
}
