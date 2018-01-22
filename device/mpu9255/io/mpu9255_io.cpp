#include "mpu9255_io.h"

#include "mpu9255/io/accelerometer/mpu9255_accel.h"
#include "mpu9255/io/gyroscope/mpu9255_gyro.h"
#include "mpu9255/io/magnetometer/mpu9255_mag.h"

#include "mpu9255_raw.h"
#include "mpu9255_reg.h"

#include <unistd.h>

#define USLEEP_TIME 200000

MPU9255_IO::MPU9255_IO():
    I2C(I2C_Address::MPU9255),
    MPU9255_Calc()
{
    if(!initialize())
        throw std::runtime_error("Failed to initialize MPU9255");

    accelerometer = new MPU9255_Accel;
    gyroscope = new MPU9255_Gyro;
    magnitomter = new MPU9255_Mag;

    calibration = new MPU9255_Calibration;

    calibration = magnitomter->getCalibration(calibration);
}

MPU9255_IO::~MPU9255_IO()
{
    delete accelerometer;
    delete gyroscope;
    delete magnitomter;
}

MPU9255_AccelRawData MPU9255_IO::getRawAccel()
{
    return accelerometer->getRawAccel();
}

MPU9255_GyroRawData MPU9255_IO::getRawGyro()
{
    return gyroscope->getRawGyro();
}

MPU9255_MagRawData MPU9255_IO::getRawMag()
{
    return magnitomter->getRawMag();
}

int16_t MPU9255_IO::getRawTemperature()
{
    return read<int16_t>(I2C_Register::TEMPDATA);
}

bool MPU9255_IO::initialize()
{
    if(!check()) return false;

    write<uint8_t>(I2C_Register::PWR_MGMT_1, I2C_Value_PWR_MGMT_1::RESET_ALL);
    usleep(USLEEP_TIME);

    write<uint8_t>(I2C_Register::PWR_MGMT_1, I2C_Value_PWR_MGMT_1::RESET_CLOCK);
    write<uint8_t>(I2C_Register::PWR_MGMT_2, I2C_Value_PWR_MGMT_2::TURN_ON_ALL);
    usleep(USLEEP_TIME);

    write<uint8_t>(I2C_Register::INT_ENABLE, I2C_Value::DISABLE);   // Disable all interrupts
    write<uint8_t>(I2C_Register::INT_PIN_CFG, I2C_Value::DISABLE);
    write<uint8_t>(I2C_Register::FIFO_EN, I2C_Value::DISABLE);      // Disable FIFO
    write<uint8_t>(I2C_Register::I2C_MST_CTRL, I2C_Value::DISABLE); // Disable I2C master
    write<uint8_t>(I2C_Register::USER_CTRL, I2C_Value::DISABLE);    // Disable FIFO and I2C master modes

    write<uint8_t>(I2C_Register::INT_PIN_CFG, I2C_Value_INT_PIN_CFG::BYPASS_ENABLE); //Enable I2C bypass for magnometer
    usleep(USLEEP_TIME);

    return true;
}

bool MPU9255_IO::check()
{
    //Make sure we have the right device
    uint8_t id;

    id = read<uint8_t>(I2C_Register::CHIPID);

    if(id != uint8_t(I2C_Value_CHIPID::CHIPID))
    {
        return false;
    }

    return true;
}
