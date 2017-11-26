#include "deviceio.h"
#include "i2c.h"

#include <unistd.h>
#include <iomanip>
#include <iostream>

using namespace std;

//SDA
//0x77
//#define BUF_SIZE 121

//SDC
//0x68
//#define BUF_SIZE 127

#define BUF_SIZE 32

static unsigned char buffer[BUF_SIZE] = {0};
static pthread_mutex_t print_mutex;

static void printBuffer(const unsigned char* buffer)
{
    pthread_mutex_lock(&print_mutex);

    cout << &buffer << " ";

    for(uint16_t i = 0; i < BUF_SIZE; i++)
    {
        cout << hex             //output in hex
             << setw(2)         //each byte prints as two characters
             << setfill('0')    //fill with 0 if not enough characters
             << static_cast<unsigned int>(buffer[i])
             << " ";
    }

    cout << endl;

    pthread_mutex_unlock(&print_mutex);
}

void readCycle(DeviceIO<unsigned char, unsigned char>* i2c)
{
    while(1)
    {
        i2c->read(0x80, buffer, BUF_SIZE);
        printBuffer(buffer);

        try
        {
            cout << hex << uint64_t(i2c->read<uint64_t>(0x80)) << endl;
        }
        catch(std::runtime_error& e)
        {
            cerr << e.what() << endl;
        }

        usleep(250000);
    }
}

int main()
{
    cout << "Hello, I2C!" << endl;

    DeviceIO<unsigned char, unsigned char>* i2c = new I2C(0x77);

//    I2C* i2c = new I2C(0x68);
//    I2C* i2c = new I2C(0x77);

    readCycle(i2c);

    return 0;
}
