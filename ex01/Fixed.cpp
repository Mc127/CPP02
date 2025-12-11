#include "Fixed.hpp"

Fixed::Fixed():value(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &f)
{
    std::cout << "Copy constructor called\n";     
    this->value = f.getRawBits();
    // *this = f; corret
}

Fixed::Fixed(const int d)
{
    std::cout << "Int constructor called\n";
    this->value = d * (1 << bits);
}
Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called\n";
    this->value = roundf(num * (1 << bits));
}

Fixed& Fixed::operator=(const Fixed &f)
{
    std::cout << "Copy assignment operator called\n";      
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
    std::cout << "Destructor called\n";
}