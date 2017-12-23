#include "bmp180_calc.h"

#include "bmp180/bmp180_types.h"
#include "int24.h"

#include <utility>

BMP180_Calc::BMP180_Calc():
    BMP180()
{
}

BMP180_Calc::~BMP180_Calc()
{
    delete calibration;
}

/**************************************************************************/
/*!
    @brief  Reads the temperatures in degrees Celsius
*/
/**************************************************************************/
float BMP180_Calc::getTemperature()
{
    float temperature;
    int32_t B5;
    uint16_t rawTemperature;

    rawTemperature = getRawTemperature();
    B5 = computeB5(rawTemperature);

    temperature = (B5 + 8) >> 4;
    temperature /= 10;

    return std::move(temperature);
}

/**************************************************************************/
/*!
    @brief  Gets the compensated pressure level in Pa
*/
/**************************************************************************/
int32_t BMP180_Calc::getPressure()
{
    uint16_t rawTemperature;
    uint24_t rawPressure;
    int32_t pressure;
    int32_t x1, x2, b5, b6, x3, b3, p;
    uint32_t b4, b7;

    /* Get the raw pressure and temperature values */
    rawTemperature = getRawTemperature();
    rawPressure = getRawPressure();

    /* Temperature compensation */
    b5 = computeB5(rawTemperature);

    /* Pressure compensation */
    b6 = b5 - 4000;
    x1 = (calibration->b2 * ((b6 * b6) >> 12)) >> 11;
    x2 = (calibration->ac2 * b6) >> 11;
    x3 = x1 + x2;
    b3 = (((((int32_t)calibration->ac1) * 4 + x3) << int(mode)) + 2) >> 2;
    x1 = (calibration->ac3 * b6) >> 13;
    x2 = (calibration->b1 * ((b6 * b6) >> 12)) >> 16;
    x3 = ((x1 + x2) + 2) >> 2;
    b4 = (calibration->ac4 * (uint32_t)(x3 + 32768)) >> 15;
    b7 = ((uint32_t)(rawPressure - b3) * (50000 >> int(mode)));

    if(b7 < 0x80000000)
    {
        p = (b7 << 1) / b4;
    }
    else
    {
        p = (b7 / b4) << 1;
    }

    x1 = (p >> 8) * (p >> 8);
    x1 = (x1 * 3038) >> 16;
    x2 = (-7357 * p) >> 16;
    pressure = p + ((x1 + x2 + 3791) >> 4);

    return std::move(pressure);
}

int32_t BMP180_Calc::computeB5(int32_t rawTemperature)
{
    int32_t X1 = (rawTemperature - (int32_t)calibration->ac6) * ((int32_t)calibration->ac5) >> 15;
    int32_t X2 = ((int32_t)calibration->mc << 11) / (X1 + (int32_t)calibration->md);

    return X1 + X2;
}
