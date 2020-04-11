#ifndef OWEN_SV01_H
#define OWEN_SV01_H

#include "abstract/unit/timer.h"
#include "unit/timer_types.h"

class OWEN_SV01:
        public Timer<Time>
{
public:
    static OWEN_SV01* create();
    virtual ~OWEN_SV01() = 0;
};

inline OWEN_SV01::~OWEN_SV01() = default;

#endif // OWEN_SV01_H
