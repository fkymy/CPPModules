#include <iostream>
#include <iomanip>
#include <climits>
#include <cmath>

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

    class ImpossibleException: public std::exception {
    public:
        ImpossibleException();
        virtual const char* what() const throw();
    };

    class NonDisplayableException: public std::exception {
    public:
        NonDisplayableException();
        virtual const char* what() const throw();
    };
};

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
        if (c <= 31 || c == 127) throw NonDisplayableException();
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

}

void Converter::printDouble() const {
    std::cout << "double: ";
    std::cout << static_cast<double>(value);

    if (value == static_cast<int>(value)) {
        std::cout << ".0";
    }

    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Invalid arguments. Usage: ./convert [string]" << std::endl;
        return 1;
    }

    Converter converter(argv[1]);
    // std::cout << argv[1] << std::endl;
    converter.printChar();
    converter.printInt();
    // converter.printFloat();
    converter.printDouble();

    return 0;
}
