#include "Converter.hpp"

Converter::ImpossibleException::ImpossibleException() {}

const char* Converter::ImpossibleException::what() const throw() {
    return "impossible";
}

Converter::NonDisplayableException::NonDisplayableException() {}

const char* Converter::NonDisplayableException::what() const throw() {
    return "Non displayable";
}

Converter::Converter(const std::string& input) : input(input) {
    error = 0;

    value = atof(input.c_str());
    if (value == 0) {
        if (input.length() == 1 && !std::isdigit(input[0]))
            value = static_cast<double>(input[0]);
        // TODO: other errors?
        // - HUGE VAL?
        // - not digit?
    }
}

Converter::Converter(const Converter& other) {
    input = other.input;
    value = other.value;
    error = other.error;
}

Converter& Converter::operator=(const Converter& other) {
    if (this != &other) {
        input = other.input;
        value = other.value;
        error = other.error;
    }
    return *this;
}

Converter::~Converter() {}

void Converter::printChar() const {
    std::cout << "char: ";
    try {
        if (isnan(value) || value < CHAR_MIN || value > CHAR_MAX)
            throw ImpossibleException();
        char c = static_cast<char>(value);
        if (!std::isprint(c)) throw NonDisplayableException();
        std::cout << "'" << c << "'" << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void Converter::printInt() const {
    std::cout << "int: ";
    try {
        if (isnan(value) || value < INT_MIN || value > INT_MAX)
            throw ImpossibleException();
        std::cout << static_cast<int>(value) << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void Converter::printFloat() const {
    std::cout << "float: ";
    try {
        float f = static_cast<float>(value);
        if (!isinf(f) && !isnan(f) && (value < -FLT_MAX || value > FLT_MAX))
            throw ImpossibleException();
        std::cout << static_cast<float>(value);

        if (value == static_cast<int>(value))
            std::cout << ".0f" << std::endl;
        else
            std::cout << "f" << std::endl;

    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void Converter::printDouble() const {
    std::cout << "double: ";
    std::cout << static_cast<double>(value);

    if (value == static_cast<int>(value)) {
        std::cout << ".0";
    }

    std::cout << std::endl;
}

