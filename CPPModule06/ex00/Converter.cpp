#include "Converter.hpp"

Converter::ImpossibleException::ImpossibleException() {}

const char* Converter::ImpossibleException::what() const throw() {
    return "impossible";
}

Converter::NonDisplayableException::NonDisplayableException() {}

const char* Converter::NonDisplayableException::what() const throw() {
    return "Non displayable";
}

std::string Converter::trim(const std::string& str,
                            const std::string& whitespace) {
    const size_t begin = str.find_first_not_of(whitespace);
    if (begin == std::string::npos) return "";

    const size_t end = str.find_last_not_of(whitespace);
    const size_t range = end - begin + 1;

    return str.substr(begin, range);
}

Converter::Converter(const std::string& input)
    : input(input), value(0), error(0) {
    std::string trimmed = trim(input);
    if (trimmed.length() == 0) {
        error = 1;
        return;
    }

    const char* pStart = trimmed.c_str();
    char* pEnd;

    value = std::strtod(pStart, &pEnd);

    if (pEnd[0] != '\0') {
        std::cout << *pEnd << std::endl;
        if (value == 0 && strlen(pEnd) == 1)
            value = static_cast<double>(pEnd[0]);
        else if (!(pEnd[0] == 'f' && pEnd[1] == '\0'))
            error = 1;
    }

    if (value == HUGE_VAL) error = 1;
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
        if (error) throw ImpossibleException();
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
        if (error) throw ImpossibleException();
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
        if (error) throw ImpossibleException();
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
    try {
        if (error) throw ImpossibleException();
        std::cout << static_cast<double>(value);
        if (value == static_cast<int>(value)) {
            std::cout << ".0";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
