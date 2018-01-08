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
    write<uint8_t>(I2C_Register::CONFIG, I2C_Value::FS_250);
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
    uint8_t calRegister[6];
    calRegister[0] = (-offset->x / 4  >> 8) & 0xFF;
    calRegister[1] = (-offset->x / 4)       & 0xFF;
    calRegister[2] = (-offset->y / 4  >> 8) & 0xFF;
    calRegister[3] = (-offset->y / 4)       & 0xFF;
    calRegister[4] = (-offset->z / 4  >> 8) & 0xFF;
    calRegister[5] = (-offset->z / 4)       & 0xFF;

    //Write to register
    write<uint8_t>(I2C_Register::OFFSET_X_H, calRegister[0]);
    write<uint8_t>(I2C_Register::OFFSET_X_L, calRegister[1]);
    write<uint8_t>(I2C_Register::OFFSET_Y_H, calRegister[2]);
    write<uint8_t>(I2C_Register::OFFSET_Y_L, calRegister[3]);
    write<uint8_t>(I2C_Register::OFFSET_Z_H, calRegister[4]);
    write<uint8_t>(I2C_Register::OFFSET_Z_L, calRegister[5]);

    return true;
}
