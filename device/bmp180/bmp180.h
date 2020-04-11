#ifndef BMP180_H
#define BMP180_H

#include "abstract/bps.h"

class BMP180:
        public BPS
{
public:
    static BMP180* create();
    virtual ~BMP180() = 0;
};

inline BMP180::~BMP180() = default;

#endif // BMP180_H
