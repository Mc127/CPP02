#include "Fixed.hpp"

Fixed::Fixed():value(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &f)
{
    std::cout << "Copy constructor called\n";     
    this->value = f.getRawBits();
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

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return (value);
}

void Fixed::setRawBits(int const raw)
{
    (void)raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}