#include "Fixed.hpp"

Fixed::Fixed():rawBits(0){}

Fixed::Fixed(const Fixed &f)
{ 
    this->rawBits = f.getRawBits();
}

Fixed::Fixed(const int d)
{
    this->rawBits = d * (1 << fractionalBits);
}
Fixed::Fixed(const float num)
{
    this->rawBits = roundf(num * (1 << fractionalBits));
}

Fixed& Fixed::operator=(const Fixed &f)
{   
    if (this != &f)
    {
        this->rawBits = f.getRawBits();
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

int Fixed::getRawBits(void) const
{
    return (rawBits);
}

void Fixed::setRawBits(int const raw)
{
    this->rawBits = raw;
}
float Fixed::toFloat(void) const
{
    float result;
    result = (float)this->rawBits / (1 << fractionalBits);

    return result;
}

int Fixed::toInt(void) const
{
    int result;
    result = this->rawBits / (1 << fractionalBits);

    return result;
}

Fixed::~Fixed()
{
}

bool Fixed::operator==(const Fixed& obj) const
{
    if (this->rawBits == obj.rawBits)
        return (true);
    else
        return (false);
}
bool Fixed::operator!=(const Fixed& obj) const
{
    if (this->rawBits != obj.rawBits)
        return (true);
    else
        return (false);
}
bool Fixed::operator<=(const Fixed& obj) const
{
    if (this->rawBits <= obj.rawBits)
        return (true);
    else
        return (false);
}
bool Fixed::operator>=(const Fixed& obj) const
{
    if (this->rawBits >= obj.rawBits)
        return (true);
    else
        return (false);
}
bool Fixed::operator<(const Fixed& obj) const
{
    if (this->rawBits < obj.rawBits)
        return (true);
    else
        return (false);
}
bool Fixed::operator>(const Fixed& obj) const
{
    if (this->rawBits > obj.rawBits)
        return (true);
    else
        return (false);
}

Fixed Fixed::operator+(const Fixed& obj) const
{
    Fixed result;
    result.rawBits = this->rawBits + obj.rawBits;
    return(result);
}

Fixed Fixed::operator-(const Fixed& obj) const
{
    Fixed result;
    result.rawBits = this->rawBits - obj.rawBits;
    return(result);
}

Fixed Fixed::operator*(const Fixed& obj) const
{
    Fixed ret;
    long temp = (long)(this->rawBits * obj.rawBits);
    ret.rawBits = (int)temp / (1 << fractionalBits);

    return(ret);
}

Fixed Fixed::operator/(const Fixed& obj) const
{
    Fixed ret;
    long tmp = (long)((this->rawBits * (1 << fractionalBits)) / obj.rawBits);
    ret.rawBits = (int)tmp;

    return(ret);
}


Fixed& Fixed::operator++()
{
    this->rawBits++;
    return (*this);
}
Fixed Fixed::operator++(int)
{
    Fixed var = *this;
    ++(*this);
    return (var);
}
// & here cuz it can be assigned like this ++b = 9;
Fixed& Fixed::operator--()// --a
{
    this->rawBits--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed var = *this;
    --(*this);
    return (var);
}

Fixed& Fixed::min(Fixed &obj1, Fixed &obj2)
{
    if (obj1 > obj2)
        return (obj2);
    else
        return (obj1);
}
Fixed& Fixed::max(Fixed &obj1, Fixed &obj2)
{
    if (obj1 > obj2)
        return (obj1);
    else
        return (obj2);
}

const Fixed& Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
    if (obj1 > obj2)
        return (obj2);
    else
        return (obj1);
}
const Fixed& Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
    if (obj1 > obj2)
        return (obj1);
    else
        return (obj2);
}