#ifndef I2C_H
#define I2C_H

#include "hardware.hpp"

enum class I2C_Address: uint8_t;
enum class I2C_Register: uint8_t;

class I2C:
        public Hardware<I2C_Register, uint8_t>
{
public:
    explicit I2C(const I2C_Address& addr);
    virtual ~I2C();

    ///Hardware
    //Max length is 32 bytes
    virtual bool readBuf(const I2C_Register& reg, uint8_t* buf, uint8_t len) override final;
    virtual bool writeBuf(const I2C_Register& reg, uint8_t* buf, uint8_t len) override final;
    //~Hardware

private:
    int32_t setup();

private:
    I2C_Address _addr;
    int _file_i2c = 0;
};

#endif // I2C_H
