#ifndef DEVICEIO_H
#define DEVICEIO_H

#include <cstdint>
#include <stdexcept>
#include <utility>

#define IO_READ_LEN_MAX 32

template<typename Register, typename Byte>
class DeviceIO
{
public:
    explicit DeviceIO();
    virtual ~DeviceIO();

    //Max read len is 32 bytes
    virtual bool read(const Register& reg, Byte* buf, uint8_t len) = 0;
    virtual bool write(const Register& reg, Byte* buf, uint8_t len) = 0;

    template<typename Value> Value read(const Register& reg);
    template<typename Size, typename Value> bool write(const Register& reg, const Value& val);

private:
    unsigned char* _io_buf;
};

template<typename Register, typename Byte>
DeviceIO<Register, Byte>::DeviceIO():
    _io_buf(new unsigned char[IO_READ_LEN_MAX])
{
}

template<typename Register, typename Byte>
DeviceIO<Register, Byte>::~DeviceIO()
{
    delete[] _io_buf;
}

template<typename Register, typename Byte>
template<typename Value>
Value DeviceIO<Register, Byte>::read(const Register& reg)
{
    Value value = 0;
    uint8_t size = uint8_t(sizeof(Value));

    if(size > IO_READ_LEN_MAX)
        size = IO_READ_LEN_MAX;

    if(!read(reg, _io_buf, size))
        throw std::runtime_error("Failed to read from the device");

    for(uint8_t i = 0; i < size; i++)
        value |= (static_cast<Value>(_io_buf[i]) << 8 * (size - (i + 1)));

    return std::forward<Value>(value);
}

template<typename Register, typename Byte>
template<typename Size, typename Value>
bool DeviceIO<Register, Byte>::write(const Register& reg, const Value& val)
{
    uint8_t size = uint8_t(sizeof(Size));

    if(size > IO_READ_LEN_MAX)
        size = IO_READ_LEN_MAX;

    for(uint8_t i = 0; i < size; i++)
        _io_buf[size - (i + 1)] |= (val >> (8 * i)) & 0xFF;

    if(!write(reg, _io_buf, size))
        throw std::runtime_error("Failed to write to the device");

    return true;
}

#endif // DEVICEIO_H
