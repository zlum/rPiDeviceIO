#ifndef BMP180_BAR_H
#define BMP180_BAR_H

#include "i2c/i2c.h"

enum class BMP180_Mode: uint8_t;
class uint24_t;

class BMP180_Bar:
        public virtual I2C
{
public:
    explicit BMP180_Bar(const BMP180_Mode& mode);
    virtual ~BMP180_Bar();

    virtual uint24_t getRawPressure();

protected:
    BMP180_Mode mode = BMP180_Mode(0);
};

#endif // BMP180_BAR_H
