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

    template<typename Int> Int read(const Register& reg);

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
template<typename Int>
Int DeviceIO<Register, Byte>::read(const Register& reg)
{
    Int value = 0;
    uint8_t size = uint8_t(sizeof(Int));

    if(size > IO_READ_LEN_MAX)
        size = IO_READ_LEN_MAX;

    if(!read(reg, _io_buf, size))
        throw std::runtime_error("Failed to read from the device");

    for(uint8_t i = 0; i < size; i++)
        value |= (static_cast<Int>(_io_buf[i]) << 8 * (size - (i + 1)));

    return std::forward<Int>(value);
}

#endif // DEVICEIO_H
