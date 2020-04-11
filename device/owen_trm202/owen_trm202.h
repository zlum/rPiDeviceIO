#ifndef OWEN_TRM202_H
#define OWEN_TRM202_H

#include <cstdint>

struct OWEN_TRM202_Data
{
    uint16_t channel1 = 0;
    uint16_t channel2 = 0;
};

class OWEN_TRM202
{
public:
    static OWEN_TRM202* create(int addr);
    virtual ~OWEN_TRM202() = 0;

    virtual OWEN_TRM202_Data getData() = 0;
};

inline OWEN_TRM202::~OWEN_TRM202() = default;

#endif // OWEN_TRM202_H
