#ifndef OWEN_SV01_REG_H
#define OWEN_SV01_REG_H

#include <cstdint>

/*-----------------------------------------------------------------------
ADDRESSES
-----------------------------------------------------------------------*/
enum class Modbus_Address: uint32_t
{
    OWEN_SV01           = 0x01
};

/*-----------------------------------------------------------------------
REGISTERS
-----------------------------------------------------------------------*/
enum class Modbus_Register: uint32_t
{
    TIMEVALUE           = 0x16
};

#endif // OWEN_SV01_REG_H
