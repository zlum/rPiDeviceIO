#ifndef INTEGER_HPP
#define INTEGER_HPP

#include "operators.hpp"

template<typename Int, typename Signedness, uint8_t Size>
class Integer:
        public Operators<Int, Signedness, Size>
{
public:
    inline Int& operator ++();
    inline Int operator ++(int);
    inline Int& operator --();
    inline Int operator --(int);

    inline Int& operator +=(const Int& rhs);
    inline Int& operator -=(const Int& rhs);
    inline Int& operator *=(const Int& rhs);
    inline Int& operator /=(const Int& rhs);
    inline Int& operator %=(const Int& rhs);

    inline unsigned operator >>=(const Int& rhs);
    inline unsigned operator <<=(const Int& rhs);
    inline unsigned operator |=(const Int& rhs);
    inline unsigned operator &=(const Int& rhs);
    inline unsigned operator ^=(const Int& rhs);
};

template<typename Int, typename Signedness, uint8_t Size>
Int& Integer<Int, Signedness, Size>::operator ++()
{
    return operator +=(1);
}

template<typename Int, typename Signedness, uint8_t Size>
Int Integer<Int, Signedness, Size>::operator ++(int)
{
    Int tmp = *this;
    operator +=(1);

    return tmp;
}

template<typename Int, typename Signedness, uint8_t Size>
Int& Integer<Int, Signedness, Size>::operator --()
{
    return operator -=(1);
}

template<typename Int, typename Signedness, uint8_t Size>
Int Integer<Int, Signedness, Size>::operator --(int)
{
    Int tmp = *this;
    operator -=(1);

    return tmp;
}

template<typename Int, typename Signedness, uint8_t Size>
Int& Integer<Int, Signedness, Size>::operator +=(const Int& rhs)
{
    return Conversion<Int, Signedness, Size>::operator =(*this + rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
Int& Integer<Int, Signedness, Size>::operator -=(const Int& rhs)
{
    return Conversion<Int, Signedness, Size>::operator =(*this - rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
Int& Integer<Int, Signedness, Size>::operator *=(const Int& rhs)
{
    return Conversion<Int, Signedness, Size>::operator =(*this * rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
Int& Integer<Int, Signedness, Size>::operator /=(const Int& rhs)
{
    return Conversion<Int, Signedness, Size>::operator =(*this / rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
Int& Integer<Int, Signedness, Size>::operator %=(const Int& rhs)
{
    return Conversion<Int, Signedness, Size>::operator =(*this % rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
unsigned Integer<Int, Signedness, Size>::operator >>=(const Int& rhs)
{
    return unsigned(Conversion<Int, Signedness, Size>::operator =
            (Signedness(this->operator >>(rhs))));
}

template<typename Int, typename Signedness, uint8_t Size>
unsigned Integer<Int, Signedness, Size>::operator <<=(const Int& rhs)
{
    return unsigned(Conversion<Int, Signedness, Size>::operator =
            (Signedness(this->operator <<(rhs))));
}

template<typename Int, typename Signedness, uint8_t Size>
unsigned Integer<Int, Signedness, Size>::operator |=(const Int& rhs)
{
    return unsigned(Conversion<Int, Signedness, Size>::operator =
            (Signedness(this->operator |(rhs))));
}

template<typename Int, typename Signedness, uint8_t Size>
unsigned Integer<Int, Signedness, Size>::operator &=(const Int& rhs)
{
    return unsigned(Conversion<Int, Signedness, Size>::operator =
            (Signedness(this->operator &(rhs))));
}

template<typename Int, typename Signedness, uint8_t Size>
unsigned Integer<Int, Signedness, Size>::operator ^=(const Int& rhs)
{
    return unsigned(Conversion<Int, Signedness, Size>::operator =
            (Signedness(this->operator ^(rhs))));
}

#endif // INTEGER_HPP
