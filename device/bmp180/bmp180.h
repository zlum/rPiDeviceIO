#ifndef BMP180_H
#define BMP180_H

#include <cstdint>

class BMP180
{
public:
    static BMP180* create();
    virtual ~BMP180() = 0;

    virtual float getTemperature() = 0;
    virtual int32_t getPressure() = 0;
};

inline BMP180::~BMP180() {}

#endif // BMP180_H
