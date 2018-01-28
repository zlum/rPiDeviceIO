#ifndef BMP180_H
#define BMP180_H

#include "abstract/bps.h"

class BMP180:
        public BPS
{
public:
    static BMP180* create();
    virtual ~BMP180() = 0;

    virtual Pressure getPressure() override = 0;
    virtual Temperature getTemperature() override = 0;
};

inline BMP180::~BMP180() {}

#endif // BMP180_H
