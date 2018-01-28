#ifndef BAROMETER_H
#define BAROMETER_H

template<typename Pascal>
class Barometer
{
public:
    virtual ~Barometer() = 0;

    virtual Pascal getPressure() = 0;
};

template<typename Pascal>
inline Barometer<Pascal>::~Barometer() {}

#endif // BAROMETER_H
