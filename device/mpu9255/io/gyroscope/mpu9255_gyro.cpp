#include "mpu9255_gyro.h"

#include "mpu9255_gyro_reg.h"
#include "mpu9255/io/mpu9255_raw.h"

#include <unistd.h>

#define USLEEP_TIME 200000
#define AVERAGE 1000.0

MPU9255_Gyro::MPU9255_Gyro():
    I2C(I2C_Address::MPU9255_GYRO)
{
    if(!initialize())
        throw std::runtime_error("Failed to initialize MPU9255 gyroscope");
}

MPU9255_Gyro::~MPU9255_Gyro()
{
    delete offset;
}

MPU9255_GyroRawData MPU9255_Gyro::getRawGyro()
{
    MPU9255_GyroRawData data;

    data.x = read<int16_t>(I2C_Register::X);
    data.y = read<int16_t>(I2C_Register::Y);
    data.z = read<int16_t>(I2C_Register::Z);

    return std::move(data);
}

bool MPU9255_Gyro::initialize()
{
    write<uint8_t>(I2C_Register::GYRO_CONFIG,
                   uint8_t(I2C_Value_GYRO_CONFIG::FSR_250) +
                   ((uint8_t(I2C_Value_CONFIG::LPF_3600) >> 3) & 3));

    write<uint8_t>(I2C_Register::CONFIG,
                   uint8_t(I2C_Value_CONFIG::LPF_3600) & 7);

    usleep(USLEEP_TIME);

    offset = accumGyroOffset();
    setGyroOffset(offset);

    return true;
}

MPU9255_GyroRawData* MPU9255_Gyro::accumGyroOffset()
{
    //Initializes gyroscopes offset
    uint16_t i;
    int64_t	tempGx = 0, tempGy = 0, tempGz = 0;
    MPU9255_GyroRawData* offset = new MPU9255_GyroRawData;

    for(i = 0; i < uint16_t(AVERAGE); i++)
    {
        const MPU9255_GyroRawData& data = getRawGyro();

        tempGx += data.x;
        tempGy += data.y;
        tempGz += data.z;

        usleep(1000);
    }

    offset->x = tempGx / AVERAGE;
    offset->y = tempGy / AVERAGE;
    offset->z = tempGz / AVERAGE;

    return offset;
}

bool MPU9255_Gyro::setGyroOffset(MPU9255_GyroRawData* offset)
{
    if(offset == nullptr) return false;

    // Divide by 4 to get 32.9 LSB per deg/s to conform to expected bias input format
    // Biases are additive, so change sign on calculated average gyro biases
    write<int16_t>(I2C_Register::OFFSET_X, -offset->x / 4);
    write<int16_t>(I2C_Register::OFFSET_Y, -offset->y / 4);
    write<int16_t>(I2C_Register::OFFSET_Z, -offset->z / 4);

    return true;
}
