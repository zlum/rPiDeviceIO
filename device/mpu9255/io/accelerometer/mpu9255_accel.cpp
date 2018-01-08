#include "mpu9255_accel.h"

#include "mpu9255_accel_reg.h"
#include "mpu9255/io/mpu9255_raw.h"

#include <unistd.h>

#define USLEEP_TIME 200000
#define AVERAGE 1000.0
#define ZNORMAL 16384 //Gravity compensation value

MPU9255_Accel::MPU9255_Accel():
    I2C(I2C_Address::MPU9255_ACCEL)
{
    if(!initialize())
        throw std::runtime_error("Failed to initialize MPU9255 accelerometer");
}

MPU9255_Accel::~MPU9255_Accel()
{
    delete offset;
}

MPU9255_AccelRawData MPU9255_Accel::getRawAccel()
{
    MPU9255_AccelRawData data;

    data.x = read<int16_t>(I2C_Register::X);
    data.y = read<int16_t>(I2C_Register::Y);
    data.z = read<int16_t>(I2C_Register::Z);

    return std::move(data);
}

bool MPU9255_Accel::initialize()
{
    //Accelerometer to 1 kHz
    write<uint8_t>(I2C_Register::CONFIG_2, I2C_Value::HZ_1130);
    write<uint8_t>(I2C_Register::CONFIG_1, I2C_Value::FS_2);
    usleep(USLEEP_TIME);

    offset = accumAccelOffset();
    setAccelOffset(offset);

    return true;
}

MPU9255_AccelRawData* MPU9255_Accel::accumAccelOffset()
{
    //Initializes accelerometer offset
    uint16_t i;
    int64_t	tempGx = 0, tempGy = 0, tempGz = 0;
    MPU9255_AccelRawData* offset = new MPU9255_AccelRawData;

    for(i = 0; i < uint16_t(AVERAGE); i++)
    {
        const MPU9255_AccelRawData& data = getRawAccel();

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

bool MPU9255_Accel::setAccelOffset(MPU9255_AccelRawData* offset)
{
    if(offset == nullptr) return false;

    //Get offsets
    uint8_t calRegister[6];
    int32_t accel_bias_reg[3] = {0, 0, 0};

    accel_bias_reg[0] = read<int16_t>(I2C_Register::OFFSET_X_H);
    accel_bias_reg[1] = read<int16_t>(I2C_Register::OFFSET_Y_H);
    accel_bias_reg[2] = read<int16_t>(I2C_Register::OFFSET_Z_H);

    accel_bias_reg[0] -= (offset->x / 8);
    accel_bias_reg[1] -= (offset->y / 8);
    accel_bias_reg[2] -= (offset->z / 8);

    calRegister[0] = (accel_bias_reg[0]  >> 8) & 0xFF;
    calRegister[1] = (accel_bias_reg[0])       & 0xFF;

    calRegister[1] = calRegister[1] & 0b11111110;

    calRegister[2] = (accel_bias_reg[1]  >> 8) & 0xFF;
    calRegister[3] = (accel_bias_reg[1])       & 0xFF;

    calRegister[3] = calRegister[3] & 0b11111110;

    calRegister[4] = (accel_bias_reg[2]  >> 8) & 0xFF;
    calRegister[5] = (accel_bias_reg[2])       & 0xFF;

    calRegister[5] = calRegister[5] & 0b11111110;

    //Write to register
    write<uint8_t>(I2C_Register::OFFSET_X_H, calRegister[0]);
    write<uint8_t>(I2C_Register::OFFSET_X_L, calRegister[1]);
    write<uint8_t>(I2C_Register::OFFSET_Y_H, calRegister[2]);
    write<uint8_t>(I2C_Register::OFFSET_Y_L, calRegister[3]);
    write<uint8_t>(I2C_Register::OFFSET_Z_H, calRegister[4]);
    write<uint8_t>(I2C_Register::OFFSET_Z_L, calRegister[5]);

    return true;
}
