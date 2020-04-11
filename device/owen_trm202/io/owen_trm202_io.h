#pragma once

#include "modbus_prot/modbus.h"
#include "owen_trm202/owen_trm202.h"

class OWEN_TRM202_IO:
        public Modbus,
        public OWEN_TRM202
{
public:
    explicit OWEN_TRM202_IO(Modbus_Address addr);
    virtual ~OWEN_TRM202_IO() = default;

    // OWEN_TRM202
    virtual OWEN_TRM202_Data getData() override final;
};
