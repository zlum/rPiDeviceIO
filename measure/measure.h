#ifndef MEASURE_H
#define MEASURE_H

namespace measure
{
    double Pa_mmHG(double pressure);
    double mmHG_Pa(double pressure);
    double pressureToAltitude(double seaLevel, double atmospheric);
    double seaLevelForAltitude(double altitude, double atmospheric);
} // namespace measure

#endif // MEASURE_H
