#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
class Fixed
{
    private:
        int rawBits;
        static const int fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &f);
        Fixed(const int nb);
        Fixed(const float num);
        Fixed& operator=(const Fixed &f);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        bool operator==(const Fixed& obj) const;
        bool operator!=(const Fixed& obj) const;
        bool operator<=(const Fixed& obj) const;
        bool operator>=(const Fixed& obj) const;
        bool operator<(const Fixed& obj) const;
        bool operator>(const Fixed& obj) const;
        Fixed operator+(const Fixed& obj) const;
        Fixed operator-(const Fixed& obj) const;
        Fixed operator*(const Fixed& obj) const;
        Fixed operator/(const Fixed& obj) const;
        Fixed operator++(int);
        Fixed& operator++();
        Fixed operator--(int);
        Fixed& operator--();
        static Fixed& min(Fixed &obj1, Fixed &obj2);
        static Fixed& max(Fixed &obj1, Fixed &obj2);
        static const Fixed& min(const Fixed &obj1, const Fixed &obj2);
        static const Fixed& max(const Fixed &obj1, const Fixed &obj2); 
        ~Fixed();
    };
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif