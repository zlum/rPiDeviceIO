#include "int24_t.h"

int24_t::int24_t():
    int24_t(0)
{
}

int24_t::int24_t(unsigned val)
{
    memcpy(_byte, &val, 3);
}

std::ostream& operator <<(std::ostream& os, const int24_t& obj)
{
    return os << signed(obj);
}
