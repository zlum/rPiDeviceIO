#include "modbus.h"

#include <cerrno>
#include <modbus/modbus.h>

#include <iostream>
#include <stdexcept>

using namespace std;

Modbus::Modbus(const Modbus_Address& addr):
    _addr(addr),
    _ctx(nullptr)
{
    // TODO: Move setup() call from constructor
    if(int32_t res = setup(); res != 0)
    {
        cerr << modbus_strerror(errno) << endl;
        throw runtime_error("Can`t setup Modbus!");
    }
}

Modbus::~Modbus()
{
    modbus_close(_ctx);
    modbus_free(_ctx);
}

bool Modbus::readBuf(const Modbus_Register& reg, uint16_t* buf, uint8_t len)
{
    int32_t res = modbus_read_registers(_ctx, int(reg), len / 2, buf);

    if(res != len)
    {
        cerr << "Failed to read from Modbus device" << endl;
        cerr << modbus_strerror(errno) << endl;
    }

    return res == len;
}

bool Modbus::writeBuf(const Modbus_Register& reg, uint16_t* buf, uint8_t len)
{
    int32_t res = modbus_write_registers(_ctx, int(reg), len / 2, buf);

    if(res != len)
    {
        cerr << "Failed to write to Modbus device" << endl;
        cerr << modbus_strerror(errno) << endl;
    }

    return res == len;
}

int32_t Modbus::setup()
{
    _ctx = modbus_new_rtu("/dev/ttyUSB0", 57600, 'N', 8, 1);

    if(int32_t res = modbus_connect(_ctx); res != 0)
    {
        modbus_free(_ctx);
        return res;
    }

    if(int32_t res = modbus_set_slave(_ctx, int(_addr)); res != 0)
    {
        return res;
    }

    return 0;
}
