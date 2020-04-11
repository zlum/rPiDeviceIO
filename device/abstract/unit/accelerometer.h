#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

template<typename AccelData>
class Accelerometer
{
public:
    virtual ~Accelerometer() = 0;

    virtual AccelData getAccel() = 0;
};

template<typename AccelData>
inline Accelerometer<AccelData>::~Accelerometer() = default;

#endif // ACCELEROMETER_H
