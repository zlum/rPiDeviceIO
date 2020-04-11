#ifndef THERMOMETER_H
#define THERMOMETER_H

template<typename Celsius>
class Thermometer
{
public:
    virtual ~Thermometer() = 0;

    virtual Celsius getTemperature() = 0;
};

template<typename Celsius>
inline Thermometer<Celsius>::~Thermometer() = default;

#endif // THERMOMETER_H
