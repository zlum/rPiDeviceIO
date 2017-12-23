#include "uint24_t.h"

uint24_t::uint24_t():
    uint24_t(0)
{
}

uint24_t::uint24_t(unsigned val)
{
    memcpy(_byte, &val, 3);
}

std::ostream& operator <<(std::ostream& os, const uint24_t& obj)
{
    return os << unsigned(obj);
}
