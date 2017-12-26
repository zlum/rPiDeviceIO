#ifndef BMP180_IO_H
#define BMP180_IO_H

#include "i2c/i2c.h"
#include "bmp180/calc/bmp180_calc.h"

class BMP180_IO:
        public I2C,
        public BMP180_Calc
{
public:
    explicit BMP180_IO(const BMP180_Mode& mode = BMP180_Mode(1));
    virtual ~BMP180_IO();

    ///BMP180_Calc
    virtual uint16_t getRawTemperature() override final;
    virtual uint24_t getRawPressure() override final;
    //~BMP180_Calc

private:
    bool initialize(const BMP180_Mode& mode);
    BMP180_Calibration* getCalibration();
};

#endif // BMP180_IO_H
