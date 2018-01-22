#include "mpu9255.h"

#include "mpu9255/io/mpu9255_io.h"

MPU9255* MPU9255::create()
{
    return new MPU9255_IO();
}
