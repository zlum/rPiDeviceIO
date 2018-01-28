#include "bps.h"

#include "bmp180/bmp180.h"

BPS* BPS::create(Device::BPS name)
{
    switch(name)
    {
    case Device::BPS::BMP180:
        return BMP180::create();
    default:
        break;
    }

    return nullptr;
}
