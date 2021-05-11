#include <cctype>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string stringToUpper(string s) {
    for (string::iterator itr = s.begin(); itr != s.end(); ++itr)
        *itr = (char)std::toupper(*itr);
    return s;
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
