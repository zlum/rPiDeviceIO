//#include "bmp180/bmp180.h"
//#include "mpu9255/mpu9255.h"

#include "device.h"
#include "measure.h"

//#include "hardware.hpp"
//#include "i2c/i2c.h"
//#include "bmp180/io/bmp180_io.h"
//#include "bmp180/bmp180_types.h"
//#include "int24.h"

#include <unistd.h>
#include <iomanip>
#include <iostream>

using namespace std;

//#define BUF_SIZE 2

//static uint8_t buffer[BUF_SIZE] = {0};
//static pthread_mutex_t print_mutex;

//static void printBuffer(const uint8_t* buffer)
//{
//    pthread_mutex_lock(&print_mutex);

//    cout << &buffer << " ";

//    for(uint16_t i = 0; i < BUF_SIZE; i++)
//    {
//        cout << hex             //output in hex
//             << setw(2)         //each byte prints as two characters
//             << setfill('0')    //fill with 0 if not enough characters
//             << static_cast<unsigned int>(buffer[i])
//             << " ";
//    }

//    cout << endl;

//    pthread_mutex_unlock(&print_mutex);
//}

void readCycle(BPS* bps)
{
//    BMP180_IO* i2c = dynamic_cast<BMP180_IO*>(bmp180);

    while(1)
    {
//        i2c->readBuf(I2C_Register::TEMPDATA, buffer, BUF_SIZE);
//        printBuffer(buffer);

//        try
//        {
//            i2c->write<uint8_t>(I2C_Register::CONTROL, I2C_Value::READTEMP);
//            usleep(250000);
//            cout << hex << uint16_t(i2c->read<uint16_t>(I2C_Register::TEMPDATA)) << endl;
//        }
//        catch(runtime_error& e)
//        {
//            cerr << e.what() << endl;
//        }

//        usleep(250000);

        cout << "Pressure: " << measure::Pa_mmHG(bps->getPressure().value) << "\t";
        cout << "Temperature: " << bps->getTemperature().value << endl;

        usleep(250000);
    }
}

void readCycle(IMU* imu)
{
    AccelData accel;
    GyroData gyro;
    MagData mag;

    while(1)
    {
        accel = imu->getAccel();
        gyro = imu->getGyro();
        mag = imu->getMag();

        cout << "ACCEL: \t " << accel.x << " " << accel.y << " " << accel.z << endl;
        cout << "GYRO: \t " << gyro.x << " " << gyro.y << " " << gyro.z << endl;
        cout << "MAG: \t " << mag.x << " " << mag.y << " " << mag.z << endl;
        cout << endl;

        usleep(250000);
    }
}

int main()
{
    cout << "Hello, I2C!" << endl;

    BPS* bps = Device::createBPS(Device::BPS::BMP180);
    readCycle(bps);

//    IMU* imu = Device::createIMU(Device::IMU::MPU9255);
//    readCycle(imu);

    return 0;
}
