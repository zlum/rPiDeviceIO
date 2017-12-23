#ifndef MEASURE_H
#define MEASURE_H

namespace measure
{
    float Pa_mmHG(float pressure);
    float mmHG_Pa(float pressure);
    float pressureToAltitude(float seaLevel, float atmospheric);
    float seaLevelForAltitude(float altitude, float atmospheric);
}

#endif // MEASURE_H
