#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
    Fixed();
    Fixed(const int num);
    Fixed(const float num);
    ~Fixed();

    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;

private:
    int raw;
    static const int b = 8;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif /* FIXED_HPP */
