#include "owen_sv01.h"

#include "owen_sv01/io/owen_sv01_io.h"

OWEN_SV01* OWEN_SV01::create()
{
    return new OWEN_SV01_IO();
}
