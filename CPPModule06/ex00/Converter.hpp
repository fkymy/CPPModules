#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <cfloat>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>

class Converter {
private:
    std::string input;
    double value;
    int error;

    Converter();

public:
    Converter(const std::string& input);
    Converter(const Converter& other);
    Converter& operator=(const Converter& other);
    ~Converter();

    void printChar() const;
    void printInt() const;
    void printFloat() const;
    void printDouble() const;

    class ImpossibleException : public std::exception {
    public:
        ImpossibleException();
        virtual const char* what() const throw();
    };

    class NonDisplayableException : public std::exception {
    public:
        NonDisplayableException();
        virtual const char* what() const throw();
    };
};

#endif /* CONVERTER_HPP */
