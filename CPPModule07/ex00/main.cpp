#include <string>
#include <iostream>

#include "whatever.hpp"

int main( void ) {
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

#ifdef TEST
    int e = -42;
    std::cout << "min( e, e ) = " << ::min( e, e ) << std::endl;
    std::cout << "max( e, e ) = " << ::max( e, e ) << std::endl;
    ::swap(e, e);
    std::cout << "e = " << e << std::endl;

    char f = 'f';
    char g = 'g';
    ::swap(f, g);
    std::cout << "f = " << f << ", g = " << g << std::endl;
    std::cout << "min( f, g ) = " << ::min( f, g ) << std::endl;
    std::cout << "max( f, g ) = " << ::max( f, g ) << std::endl;

#endif
    return 0;
}
