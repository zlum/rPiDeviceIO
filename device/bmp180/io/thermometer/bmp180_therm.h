#ifndef BMP180_THERM_H
#define BMP180_THERM_H

#include "i2c/i2c.h"

#include <cstdint>

class BMP180_Therm:
        public virtual I2C
{
public:
    explicit BMP180_Therm();
    virtual ~BMP180_Therm();

    virtual uint16_t getRawTemperature();
};

#endif // BMP180_THERM_H
