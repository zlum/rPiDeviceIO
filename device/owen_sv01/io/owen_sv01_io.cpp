#include "owen_sv01_io.h"

#include "owen_sv01_reg.h"

OWEN_SV01_IO::OWEN_SV01_IO():
    Modbus(Modbus_Address::OWEN_SV01)
{
}

Time OWEN_SV01_IO::getTime()
{
    return Time{uint64_t(read<uint16_t>(Modbus_Register::TIMEVALUE) * 100000)};
}
