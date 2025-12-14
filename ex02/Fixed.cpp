#include "Fixed.hpp"

Fixed::Fixed():value(0){}

Fixed::Fixed(const Fixed &f)
{ 
    this->value = f.getRawBits();
}

Fixed::Fixed(const int d)
{
    this->value = d * (1 << bits);
}
Fixed::Fixed(const float num)
{
    this->value = roundf(num * (1 << bits));
}

Fixed& Fixed::operator=(const Fixed &f)
{   
    if (this != &f)
    {
        this->value = f.getRawBits();
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
    return (value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}
float Fixed::toFloat(void) const
{
    float result;
    result = (float)this->value / (1 << bits);
    return result;
}

int Fixed::toInt(void) const
{
    int result;
    result = this->value / (1 << bits);

    return result;
}

Fixed::~Fixed()
{
}

bool Fixed::operator==(Fixed& obj) const
{
    if (this->value == obj.value)
        return (true);
    else
        return (false);
}
bool Fixed::operator!=(Fixed& obj) const
{
    if (this->value != obj.value)
        return (true);
    else
        return (false);
}
bool Fixed::operator<=(Fixed& obj) const
{
    if (this->value <= obj.value)
        return (true);
    else
        return (false);
}
bool Fixed::operator>=(Fixed& obj) const
{
    if (this->value >= obj.value)
        return (true);
    else
        return (false);
}
bool Fixed::operator<(Fixed& obj) const
{
    if (this->value < obj.value)
        return (true);
    else
        return (false);
}
bool Fixed::operator>(Fixed& obj) const
{
    if (this->value > obj.value)
        return (true);
    else
        return (false);
}