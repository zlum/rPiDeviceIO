#ifndef MPU9255_MAG_H
#define MPU9255_MAG_H

#include "i2c/i2c.h"

class MPU9255_MagRawData;

class MPU9255_Mag:
        public virtual I2C
{
public:
    explicit MPU9255_Mag();
    virtual ~MPU9255_Mag();

    virtual MPU9255_MagRawData getRawMag();

private:
    bool initialize();
    bool check();
};

#endif // MPU9255_MAG_H
