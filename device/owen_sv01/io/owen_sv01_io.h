#pragma once

#include "modbus_prot/modbus.h"
#include "owen_sv01/owen_sv01.h"

class OWEN_SV01_IO:
        public Modbus,
        public OWEN_SV01
{
public:
    explicit OWEN_SV01_IO();
    virtual ~OWEN_SV01_IO() = default;

    // Timer
    virtual Time getTime() override final;
};
