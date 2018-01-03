#ifndef HARDWARE_H
#define HARDWARE_H

#include <cstdint>
#include <cstring>
#include <stdexcept>

#define IO_LEN_MAX 32

template<typename Register, typename Byte>
class Hardware
{
public:
    explicit Hardware();
    virtual ~Hardware();

    //Max len is 32 bytes
    virtual bool readBuf(const Register& reg, Byte* buf, uint8_t len) = 0;
    virtual bool writeBuf(const Register& reg, Byte* buf, uint8_t len) = 0;

    template<typename Type>
    Type read(const Register& reg, bool bigEndian = false);
    template<typename Type, typename Value>
    bool write(const Register& reg, const Value& val, bool bigEndian = false);

private:
    Byte* _io_buf;
};

template<typename Register, typename Byte>
Hardware<Register, Byte>::Hardware():
    _io_buf(new Byte[IO_LEN_MAX])
{
}

template<typename Register, typename Byte>
Hardware<Register, Byte>::~Hardware()
{
    delete[] _io_buf;
}

template<typename Register, typename Byte>
template<typename Type>
Type Hardware<Register, Byte>::read(const Register& reg, bool bigEndian)
{
    std::memset(_io_buf, 0, IO_LEN_MAX);
    Type value = 0;
    constexpr uint8_t size = sizeof(Type) > IO_LEN_MAX ?
                                 IO_LEN_MAX : uint8_t(sizeof(Type));

    if(!readBuf(reg, _io_buf, size))
        throw std::runtime_error("Failed to read from the device");

    if(bigEndian)
    {
        memcpy(&value, _io_buf, size);
    }
    else
    {
        for(uint8_t i = 0; i < size; i++)
            value |= (static_cast<Type>(_io_buf[i]) << 8 * (size - (i + 1)));
    }

    return std::move(value);
}

template<typename Register, typename Byte>
template<typename Type, typename Value>
bool Hardware<Register, Byte>::write(const Register& reg, const Value& val, bool bigEndian)
{
    std::memset(_io_buf, 0, IO_LEN_MAX);
    constexpr uint8_t size = sizeof(Type) > IO_LEN_MAX ?
                                 IO_LEN_MAX : uint8_t(sizeof(Type));

    if(bigEndian)
    {
        memcpy(_io_buf, &val, size);
    }
    else
    {
        for(uint8_t i = 0; i < size; i++)
            _io_buf[size - (i + 1)] |= (static_cast<Type>(val) >> (8 * i)) & 0xFF;
    }

    if(!writeBuf(reg, _io_buf, size))
        throw std::runtime_error("Failed to write to the device");

    return true;
}

#endif // HARDWARE_H
