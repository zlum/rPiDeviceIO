#ifndef MAGNETOMETER_H
#define MAGNETOMETER_H

template<typename MagData>
class Magnetometer
{
public:
    virtual ~Magnetometer() = 0;

    virtual MagData getMag() = 0;
};

template<typename MagData>
inline Magnetometer<MagData>::~Magnetometer() = default;

#endif // MAGNETOMETER_H
