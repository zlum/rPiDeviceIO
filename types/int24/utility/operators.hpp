#ifndef OPERATORS_HPP
#define OPERATORS_HPP

#include "conversion.hpp"

template<typename Int, typename Signedness, uint8_t Size>
class Operators:
        public Conversion<Int, Signedness, Size>
{
public:
    inline signed operator -() const;

    inline signed operator +(const Int& rhs) const;
    inline signed operator -(const Int& rhs) const;
    inline signed operator *(const Int& rhs) const;
    inline signed operator /(const Int& rhs) const;
    inline signed operator %(const Int& rhs) const;

    inline signed operator +(const signed& rhs) const;
    inline signed operator -(const signed& rhs) const;
    inline signed operator *(const signed& rhs) const;
    inline signed operator /(const signed& rhs) const;
    inline signed operator %(const signed& rhs) const;

    inline unsigned operator >>(const Int& rhs) const;
    inline unsigned operator <<(const Int& rhs) const;
    inline unsigned operator |(const Int& rhs) const;
    inline unsigned operator &(const Int& rhs) const;
    inline unsigned operator ^(const Int& rhs) const;

    inline unsigned operator >>(const unsigned& rhs) const;
    inline unsigned operator <<(const unsigned& rhs) const;
    inline unsigned operator |(const unsigned& rhs) const;
    inline unsigned operator &(const unsigned& rhs) const;
    inline unsigned operator ^(const unsigned& rhs) const;

    inline bool operator ==(const Int& rhs) const;
    inline bool operator !=(const Int& rhs) const;
    inline bool operator <(const Int& rhs) const;
    inline bool operator >(const Int& rhs) const;
    inline bool operator <=(const Int& rhs) const;
    inline bool operator >=(const Int& rhs) const;

    inline bool operator ==(const signed& rhs) const;
    inline bool operator !=(const signed& rhs) const;
    inline bool operator <(const signed& rhs) const;
    inline bool operator >(const signed& rhs) const;
    inline bool operator <=(const signed& rhs) const;
    inline bool operator >=(const signed& rhs) const;
};

template<typename Int, typename Signedness, uint8_t Size>
int Operators<Int, Signedness, Size>::operator -() const
{
    return -(Signedness(*this));
}

template<typename Int, typename Signedness, uint8_t Size>
int Operators<Int, Signedness, Size>::operator +(const Int& rhs) const
{
    return *this + Signedness(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
int Operators<Int, Signedness, Size>::operator -(const Int& rhs) const
{
    return *this - Signedness(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
int Operators<Int, Signedness, Size>::operator *(const Int& rhs) const
{
    return *this * Signedness(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
signed Operators<Int, Signedness, Size>::operator /(const Int& rhs) const
{
    return *this / Signedness(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
signed Operators<Int, Signedness, Size>::operator %(const Int& rhs) const
{
    return *this % Signedness(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
signed Operators<Int, Signedness, Size>::operator +(const signed& rhs) const
{
    return (int(*this)) + rhs;
}

template<typename Int, typename Signedness, uint8_t Size>
signed Operators<Int, Signedness, Size>::operator -(const signed& rhs) const
{
    return (int(*this)) - rhs;
}

template<typename Int, typename Signedness, uint8_t Size>
signed Operators<Int, Signedness, Size>::operator *(const signed& rhs) const
{
    return (int(*this)) * rhs;
}

template<typename Int, typename Signedness, uint8_t Size>
signed Operators<Int, Signedness, Size>::operator /(const signed& rhs) const
{
    return (int(*this)) / rhs;
}

template<typename Int, typename Signedness, uint8_t Size>
signed Operators<Int, Signedness, Size>::operator %(const signed& rhs) const
{
    return (int(*this)) % rhs;
}

template<typename Int, typename Signedness, uint8_t Size>
unsigned Operators<Int, Signedness, Size>::operator >>(const Int& rhs) const
{
    return *this >> Signedness(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
unsigned Operators<Int, Signedness, Size>::operator <<(const Int& rhs) const
{
    return *this << Signedness(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
unsigned Operators<Int, Signedness, Size>::operator |(const Int& rhs) const
{
    return *this | Signedness(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
unsigned Operators<Int, Signedness, Size>::operator &(const Int& rhs) const
{
    return *this & Signedness(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
unsigned Operators<Int, Signedness, Size>::operator ^(const Int& rhs) const
{
    return *this ^ Signedness(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
unsigned Operators<Int, Signedness, Size>::operator >>(const unsigned& rhs) const
{
    return (Signedness(*this)) >> rhs;
}

template<typename Int, typename Signedness, uint8_t Size>
unsigned Operators<Int, Signedness, Size>::operator <<(const unsigned& rhs) const
{
    return (Signedness(*this)) << rhs;
}

template<typename Int, typename Signedness, uint8_t Size>
unsigned Operators<Int, Signedness, Size>::operator |(const unsigned& rhs) const
{
    return (Signedness(*this)) | rhs;
}

template<typename Int, typename Signedness, uint8_t Size>
unsigned Operators<Int, Signedness, Size>::operator &(const unsigned& rhs) const
{
    return (Signedness(*this)) & rhs;
}

template<typename Int, typename Signedness, uint8_t Size>
unsigned Operators<Int, Signedness, Size>::operator ^(const unsigned& rhs) const
{
    return (Signedness(*this)) ^ rhs;
}

template<typename Int, typename Signedness, uint8_t Size>
bool Operators<Int, Signedness, Size>::operator ==(const Int& rhs) const
{
    return Signedness(*this) == Signedness(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
bool Operators<Int, Signedness, Size>::operator !=(const Int& rhs) const
{
    return !this->operator ==(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
bool Operators<Int, Signedness, Size>::operator <(const Int& rhs) const
{
    return Signedness(*this) < Signedness(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
bool Operators<Int, Signedness, Size>::operator >(const Int& rhs) const
{
    return Signedness(*this) > Signedness(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
bool Operators<Int, Signedness, Size>::operator <=(const Int& rhs) const
{
    return Signedness(*this) <= Signedness(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
bool Operators<Int, Signedness, Size>::operator >=(const Int& rhs) const
{
    return Signedness(*this) >= Signedness(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
bool Operators<Int, Signedness, Size>::operator ==(const signed& rhs) const
{
    return Signedness(*this) == Signedness(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
bool Operators<Int, Signedness, Size>::operator !=(const signed& rhs) const
{
    return !this->operator ==(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
bool Operators<Int, Signedness, Size>::operator <(const signed& rhs) const
{
    return Signedness(*this) < Signedness(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
bool Operators<Int, Signedness, Size>::operator >(const signed& rhs) const
{
    return Signedness(*this) > Signedness(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
bool Operators<Int, Signedness, Size>::operator <=(const signed& rhs) const
{
    return Signedness(*this) <= Signedness(rhs);
}

template<typename Int, typename Signedness, uint8_t Size>
bool Operators<Int, Signedness, Size>::operator >=(const signed& rhs) const
{
    return Signedness(*this) >= Signedness(rhs);
}

#endif // OPERATORS_HPP
