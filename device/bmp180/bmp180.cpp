#include "bmp180.h"

#include "bmp180/io/bmp180_io.h"

BMP180* BMP180::create()
{
    return new BMP180_IO();
}
