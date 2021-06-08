#include "Converter.hpp"

// TODO: isnan is apparently C++11...

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Invalid arguments. Usage: ./convert [string]"
                  << std::endl;
        return 1;
    }

    Converter converter(argv[1]);
    converter.printChar();
    converter.printInt();
    converter.printFloat();
    converter.printDouble();
    return 0;
}
