#ifndef BPS_H
#define BPS_H

// Barometric Pressure Sensor

#include "bps_types.h"
#include "device_list.h"
#include "unit/barometer.h"
#include "unit/thermometer.h"

class BPS:
        Barometer<Pressure>,
        Thermometer<Temperature>
{
public:
    static BPS* create(Device::BPS name);
    virtual ~BPS() = 0;

    //Pressure level in Pa
    virtual Pressure getPressure() override = 0;
    //Temperature in degrees Celsius
    virtual Temperature getTemperature() override = 0;
};

inline BPS::~BPS() {}

#endif // BPS_H
