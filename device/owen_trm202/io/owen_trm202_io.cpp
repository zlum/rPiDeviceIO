#include "owen_trm202_io.h"

#include "owen_trm202_reg.h"

OWEN_TRM202_IO::OWEN_TRM202_IO(Modbus_Address addr):
    Modbus(addr)
{
}

OWEN_TRM202_Data OWEN_TRM202_IO::getData()
{
    OWEN_TRM202_Data data;

    auto res = read<uint32_t>(Modbus_Register::CHANNEL_1);

    static_assert(sizeof(OWEN_TRM202_Data) == sizeof(uint32_t));
    memcpy(static_cast<void*>(&data), &res, sizeof(res));

    return data;
}
