#ifndef BMP180_CALC_H
#define BMP180_CALC_H

#include "bmp180/bmp180.h"

enum class BMP180_Mode: uint8_t;
class uint24_t;
struct BMP180_Calibration;

class BMP180_Calc:
        public BMP180
{
public:
    explicit BMP180_Calc();
    virtual ~BMP180_Calc();

    // BPS
    virtual Pressure getPressure() override final;
    virtual Temperature getTemperature() override final;

protected:
    virtual uint24_t getRawPressure() = 0;
    virtual uint16_t getRawTemperature() = 0;

protected:
    BMP180_Calibration* calibration = nullptr;
    BMP180_Mode mode = BMP180_Mode(0);

private:
    int32_t computeB5(int32_t rawTemperature);
};

#endif // BMP180_CALC_H
