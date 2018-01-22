#ifndef CONVERSION_H
#define CONVERSION_H

#include <cstdint>
#include <cstring>

template<typename Int, typename Signedness, uint8_t Size>
class Conversion
{
};

template<typename Int, uint8_t Size>
class Conversion<Int, unsigned, Size>
{
public:
    inline Int& operator =(const unsigned& val);

    inline explicit operator bool() const;
    inline explicit operator unsigned() const;
    inline explicit operator signed() const;
    inline explicit operator float() const;
    inline explicit operator double() const;

protected:
    uint8_t _byte[Size];
};

template<typename Int, uint8_t Size>
class Conversion<Int, signed, Size>
{
public:
    inline Int& operator =(const unsigned& val);

    inline explicit operator bool() const;
    inline explicit operator unsigned() const;
    inline explicit operator signed() const;
    inline explicit operator float() const;
    inline explicit operator double() const;

protected:
    uint8_t _byte[Size];
};

template<typename Int, uint8_t Size>
Int& Conversion<Int, unsigned, Size>::operator =(const unsigned& val)
{
    memcpy(_byte, &val, Size);

    return static_cast<Int&>(*this);
}

template<typename Int, uint8_t Size>
Conversion<Int, unsigned, Size>::operator bool() const
{
    bool val = 0;
    unsigned(*this) == 0 ? val = false : val = true;

    return val;
}

template<typename Int, uint8_t Size>
Conversion<Int, unsigned, Size>::operator unsigned() const
{
    unsigned val = 0;
    memcpy(&val, &_byte, Size);

    return val;
}

template<typename Int, uint8_t Size>
Conversion<Int, unsigned, Size>::operator signed() const
{
    signed val = unsigned(*this);

    return val;
}

template<typename Int, uint8_t Size>
Conversion<Int, unsigned, Size>::operator float() const
{
    float val = unsigned(*this);

    return val;
}

template<typename Int, uint8_t Size>
Conversion<Int, unsigned, Size>::operator double() const
{
    double val = unsigned(*this);

    return val;
}

//////////////////////////////////////////////////////////////////////

template<typename Int, uint8_t Size>
Int& Conversion<Int, signed, Size>::operator =(const unsigned& val)
{
    memcpy(_byte, &val, Size);

    return static_cast<Int&>(*this);
}

template<typename Int, uint8_t Size>
Conversion<Int, signed, Size>::operator bool() const
{
    bool val = 0;
    signed(*this) == 0 ? val = false : val = true;

    return val;
}

template<typename Int, uint8_t Size>
Conversion<Int, signed, Size>::operator unsigned() const
{
    unsigned val = 0;
    memcpy(&val, &_byte, Size);

    return val;
}

template<typename Int, uint8_t Size>
Conversion<Int, signed, Size>::operator signed() const
{
    return (_byte[2] & 0x80 ? (0xFF << 24) : 0) |
            (_byte[2] << 16) |
            (_byte[1] << 8) |
            (_byte[0]);
}

template<typename Int, uint8_t Size>
Conversion<Int, signed, Size>::operator float() const
{
    float val = signed(*this);

    return val;
}

template<typename Int, uint8_t Size>
Conversion<Int, signed, Size>::operator double() const
{
    double val = signed(*this);

    return val;
}

#endif // CONVERSION_H
