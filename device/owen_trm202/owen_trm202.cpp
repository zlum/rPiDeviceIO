#include "owen_trm202.h"

#include "owen_trm202/io/owen_trm202_io.h"

OWEN_TRM202* OWEN_TRM202::create(int addr)
{
    return new OWEN_TRM202_IO(Modbus_Address(addr));
}
