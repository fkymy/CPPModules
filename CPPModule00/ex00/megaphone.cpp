#include <cctype>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string stringToUpper(char* input) {
    string result = input;
    for (string::iterator itr = result.begin(); itr != result.end(); ++itr)
        *itr = (char)std::toupper(*itr);
    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
        return 0;
    }

    for (int i = 1; i < argc; ++i)
        cout << stringToUpper(argv[i]);
    cout << endl;
    return 0;
}
