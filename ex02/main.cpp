#include "Fixed.hpp"

int main( void ) 
{
    Fixed a(3.4f);
    Fixed b(3.5f);

    if(b.operator>(a))
        std::cout << "yeah\n";
    else
        std::cout << "not equal\n";
    return 0;
}