#ifndef GYROSCOPE_H
#define GYROSCOPE_H

template<typename GyroData>
class Gyroscope
{
public:
    virtual ~Gyroscope() = 0;

    virtual GyroData getGyro() = 0;
};

template<typename GyroData>
inline Gyroscope<GyroData>::~Gyroscope() = default;

#endif // GYROSCOPE_H
