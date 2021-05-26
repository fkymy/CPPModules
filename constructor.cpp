#include <string>
#include <iostream>
using namespace std;

class Test {
    public:
        Test(int n) : n(n) {}
        string s;
        int n;
};


int main() {
    Test t(42);

    cout << t.n << endl;
    cout << t.s << endl;


    return 0;
}
