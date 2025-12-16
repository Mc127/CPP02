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
Fixed& Fixed::operator=(const Fixed &f)
{
    std::cout << "Copy assignment operator called\n";      
    if (this != &f)
    {
        this->rawBits = f.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return (rawBits);
}

void Fixed::setRawBits(int const raw)
{
    this->rawBits = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}
