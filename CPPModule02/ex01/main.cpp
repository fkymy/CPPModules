#include <iostream>

#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

#ifdef TEST
    std::cout << "MY TESTS" << std::endl;
    {
        Fixed e(0);
        e.setRawBits(0);
        std::cout << "e is " << e << ", toInt: " << e.toInt() << ", toFloat: " << e.toFloat() << std::endl;
    }
    {
        Fixed e(-1);
        std::cout << "e is " << e << ", toInt: " << e.toInt() << ", toFloat: " << e.toFloat() << std::endl;
    }
    {
        Fixed e(-256);
        std::cout << "e is " << e << ", toInt: " << e.toInt() << ", toFloat: " << e.toFloat() << std::endl;
    }
    {
        Fixed e(8388607);
        std::cout << "e is " << e << ", toInt: " << e.toInt() << ", toFloat: " << e.toFloat() << std::endl;
    }
    {
        Fixed e(-8388608);
        std::cout << "e is " << e << ", toInt: " << e.toInt() << ", toFloat: " << e.toFloat() << std::endl;
    }
    {
        Fixed e(8388608);
        std::cout << "e is " << e << ", toInt: " << e.toInt() << ", toFloat: " << e.toFloat() << std::endl;
    }
    {
        Fixed e(-8388609);
        std::cout << "e is " << e << ", toInt: " << e.toInt() << ", toFloat: " << e.toFloat() << std::endl;
    }

    Fixed g(-42.424242f);
    std::cout << "g is " << g << ", toInt: " << g.toInt() << ", toFloat: " << g.toFloat() << std::endl;
    Fixed h(-.99999999f);
    std::cout << "h is " << h << ", toInt: " << h.toInt() << ", toFloat: " << h.toFloat() << std::endl;
    Fixed i(0.00000001f);
    std::cout << "i is " << i << ", toInt: " << i.toInt() << ", toFloat: " << i.toFloat() << std::endl;
    Fixed j(.000000001f);
    std::cout << "j is " << j << ", toInt: " << j.toInt() << ", toFloat: " << j.toFloat() << std::endl;
    Fixed k(99999.99f);
    std::cout << "k is " << k << ", toInt: " << k.toInt() << ", toFloat: " << k.toFloat() << std::endl;

#endif

    return 0;
}
