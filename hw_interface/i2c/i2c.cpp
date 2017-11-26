#include "i2c.h"

#include <errno.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <iostream>
#include <stdexcept>

using namespace std;

I2C::I2C(const unsigned char& addr):
    _addr(addr)
{
    if(setup())
    {
        throw runtime_error("Can`t setup I2C!");
    }
}

I2C::~I2C()
{
}

int32_t I2C::setup()
{
    //----- OPEN THE I2C BUS -----
    char *filename = (char*)"/dev/i2c-1";
    if((_file_i2c = open(filename, O_RDWR)) < 0)
    {
        cerr << "Failed to open the i2c bus" << endl;
        cerr << "errno = " << errno << endl;

        return errno;
    }

    if(ioctl(_file_i2c, I2C_SLAVE, _addr) < 0)
    {
        cerr << "Failed to acquire bus access and/or talk to slave" << endl;
        cerr << "errno = " << errno << endl;

        return errno;
    }

    return 0;
}

bool I2C::read(const unsigned char& reg, unsigned char* buf, uint8_t len)
{
    uint8_t length = i2c_smbus_read_i2c_block_data(_file_i2c, reg, len, buf);

    if(length != len)
    {
        cerr << "Failed to read from the i2c bus" << endl;
    }

    return length == len;
}

bool I2C::write(const unsigned char& reg, unsigned char* buf, uint8_t len)
{
    uint8_t length = i2c_smbus_write_i2c_block_data(_file_i2c, reg, len, buf);

    if(length != len)
    {
        cerr << "Failed to write to the i2c bus" << endl;
    }

    return length == len;
}

int32_t I2C::read(const unsigned char& reg)
{
    int32_t res = i2c_smbus_read_byte_data(_file_i2c, reg);

    if(res < 0)
    {
        cerr << "Failed to read from the i2c bus" << endl;
    }

    return std::forward<int32_t>(res);
}

int32_t I2C::write(const unsigned char& reg, const unsigned char& val)
{
    int32_t res = i2c_smbus_write_byte_data(_file_i2c, reg, val);

    if(res < 0)
    {
        cerr << "Failed to write to the i2c bus" << endl;
    }

    return std::forward<int32_t>(res);
}
