#include "measure.h"

#include <cstdint>
#include <math.h>

/**************************************************************************/
/*!
    Calculates the pressure (in millimeters of mercury) from the specified
    pressure (in pascals).

    @param  pressure      Pressure in Pa
*/
/**************************************************************************/
float measure::Pa_mmHG(float pressure)
{
    return pressure / 133.3223684;
}

/**************************************************************************/
/*!
    Calculates the pressure (in pascals) from the specified
    pressure (in millimeters of mercury).

    @param  pressure      Pressure in mmHG
*/
/**************************************************************************/
float measure::mmHG_Pa(float pressure)
{
    return pressure * 133.3223684;
}

/**************************************************************************/
/*!
    Calculates the altitude (in meters) from the specified atmospheric
    pressure (in hPa), and sea-level pressure (in hPa).

    @param  seaLevel      Sea-level pressure in hPa
    @param  atmospheric   Atmospheric pressure in hPa
*/
/**************************************************************************/
float measure::pressureToAltitude(float seaLevel, float atmospheric)
{
    // Equation taken from BMP180 datasheet (page 16):
    // http://www.adafruit.com/datasheets/BST-BMP180-DS000-09.pdf

    // Note that using the equation from wikipedia can give bad results
    // at high altitude.  See this thread for more information:
    // http://forums.adafruit.com/viewtopic.php?f=22&t=58064

    return 44330.0 * (1.0 - pow(atmospheric / seaLevel, 0.1903));
}

/**************************************************************************/
/*!
    Calculates the pressure at sea level (in hPa) from the specified altitude
    (in meters), and atmospheric pressure (in hPa).

    @param  altitude      Altitude in meters
    @param  atmospheric   Atmospheric pressure in hPa
*/
/**************************************************************************/
float measure::seaLevelForAltitude(float altitude, float atmospheric)
{
    // Equation taken from BMP180 datasheet (page 17):
    // http://www.adafruit.com/datasheets/BST-BMP180-DS000-09.pdf

    // Note that using the equation from wikipedia can give bad results
    // at high altitude.  See this thread for more information:
    // http://forums.adafruit.com/viewtopic.php?f=22&t=58064

    return atmospheric / pow(1.0 - (altitude / 44330.0), 5.255);
}
