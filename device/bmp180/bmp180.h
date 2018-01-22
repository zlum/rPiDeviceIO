#ifndef BMP180_H
#define BMP180_H

#include <cstdint>

class BMP180
{
public:
    static BMP180* create();
    virtual ~BMP180() = 0;

    //Temperature in degrees Celsius
    virtual float getTemperature() = 0;
    //Pressure level in Pa
    virtual int32_t getPressure() = 0;
};

inline BMP180::~BMP180() {}

#endif // BMP180_H
