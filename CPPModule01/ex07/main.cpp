#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 4 || strlen(argv[1]) == 0 || strlen(argv[2]) == 0 ||
        strlen(argv[3]) == 0) {
        std::cout << "Invalid arguments." << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream input(filename);
    std::ofstream output(filename + ".replace");
    if (!input.is_open() || !output.is_open()) {
        std::cout << "Could not open file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(input, line)) {
        size_t found = line.find(s1);
        while (found != std::string::npos) {
            line.replace(found, s1.length(), s2);
            found = line.find(s1, found + s2.length());
        }
        output << line;
        if (!input.eof()) output << std::endl;
    }

    return 0;
}
