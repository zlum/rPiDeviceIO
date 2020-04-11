#pragma once

#include "hardware.hpp"

enum class Modbus_Address: uint32_t;
enum class Modbus_Register: uint32_t;

struct _modbus;
using modbus_t = _modbus;

class Modbus:
        public Hardware<Modbus_Register, uint16_t>
{
public:
    explicit Modbus(const Modbus_Address& addr);
    virtual ~Modbus();

    // Hardware
    // Max length is 32 bytes
    virtual bool readBuf(const Modbus_Register& reg,
                         uint16_t* buf, uint8_t len) override final;
    virtual bool writeBuf(const Modbus_Register& reg,
                          uint16_t* buf, uint8_t len) override final;

private:
    int32_t setup();

private:
    Modbus_Address _addr;
    modbus_t* _ctx;
};
