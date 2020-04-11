#ifndef MPU9255_ACCEL_H
#define MPU9255_ACCEL_H

#include "i2c_prot/i2c.h"

class MPU9255_AccelRawData;

class MPU9255_Accel:
        public virtual I2C
{
public:
    explicit MPU9255_Accel();
    virtual ~MPU9255_Accel();

    virtual MPU9255_AccelRawData getRawAccel();

private:
    bool initialize();
    MPU9255_AccelRawData* accumAccelOffset();
    bool setAccelOffset(MPU9255_AccelRawData* offset);

private:
    MPU9255_AccelRawData* offset = nullptr;
};

#endif // MPU9255_ACCEL_H
