#ifndef INT24_T_H
#define INT24_T_H

#include "utility/integer.hpp"

#include <iostream>

#define INT24_MAX 8388607
#define INT24_MIN -8388608

class int24_t:
        public Integer<int24_t, signed, 3>
{
public:
    int24_t();
    int24_t(unsigned val);

    friend std::ostream& operator <<(std::ostream& os, const int24_t& obj);
};

#endif // INT24_T_H
