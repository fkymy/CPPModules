#include "Converter.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Invalid arguments. Usage: ./convert [string]"
                  << std::endl;
        return 1;
    }

    Converter converter(argv[1]);
    // TODO: Remove this
    std::cout << "===== Converting string: " << argv[1] << std::endl;
    converter.printChar();
    converter.printInt();
    converter.printFloat();
    converter.printDouble();
    return 0;
}
