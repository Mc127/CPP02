#include "Fixed.hpp"

Fixed::Fixed():rawBits(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &f)
{
    std::cout << "Copy constructor called\n";     
    this->rawBits = f.getRawBits();
}

Fixed::Fixed(const int d)
{
    std::cout << "Int constructor called\n";
    this->rawBits = d * (1 << fractionalBits);
}
Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called\n";
    this->rawBits = roundf(num * (1 << fractionalBits));
}

Fixed& Fixed::operator=(const Fixed &f)
{
    std::cout << "Copy assignment operator called\n";      
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
    std::cout << "Destructor called\n";
}