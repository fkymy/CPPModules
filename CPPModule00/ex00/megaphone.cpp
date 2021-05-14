#include <cctype>
#include <iostream>
#include <string>

std::string stringToUpper(std::string s) {
    for (std::string::iterator itr = s.begin(); itr != s.end(); ++itr)
        *itr = (char)std::toupper(*itr);
    return s;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; ++i)
        std::cout << stringToUpper(argv[i]);
    std::cout << std::endl;
    return 0;
}
