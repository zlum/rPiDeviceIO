#ifndef MPU9255_MAG_H
#define MPU9255_MAG_H

#include "i2c/i2c.h"

struct MPU9255_Calibration;
struct MPU9255_MagAdjustment;
struct MPU9255_MagRawData;

class MPU9255_Mag:
        public virtual I2C
{
public:
    explicit MPU9255_Mag();
    virtual ~MPU9255_Mag();

    virtual MPU9255_MagRawData getRawMag();
    virtual MPU9255_Calibration* getCalibration(MPU9255_Calibration* calibration) const;

protected:
    MPU9255_MagAdjustment* adjustment = nullptr;

private:
    bool initialize();
    bool check();
    bool reboot();
    MPU9255_MagAdjustment* getAdjustment();
};

#endif // MPU9255_MAG_H
