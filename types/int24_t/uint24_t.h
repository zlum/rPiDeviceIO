#ifndef UINT24_T_H
#define UINT24_T_H

#include "utility/integer.hpp"

#include <iostream>

#define UINT24_MAX 16777215

class uint24_t:
        public Integer<uint24_t, unsigned, 3>
{
public:
    uint24_t();
    uint24_t(unsigned val);

    friend std::ostream& operator <<(std::ostream& os, const uint24_t& obj);
};

#endif // UINT24_T_H
