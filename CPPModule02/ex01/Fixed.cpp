#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : raw(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
    std::cout << "Int constructor called" << std::endl;
    raw = num << b;
}

Fixed::Fixed(const float num) {
    std::cout << "Float constructor called" << std::endl;
    raw = (int)roundf(num * (1 << b));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
        raw = other.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const {
    return raw;
}

void Fixed::setRawBits( int const raw) {
    this->raw = raw;
}

int Fixed::toInt( void ) const {
    return raw >> b;
}

float Fixed::toFloat( void ) const {
    return (float)raw / (float)(1 << b);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& f) {
    stream << f.toFloat();
    return stream;
}
