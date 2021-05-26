#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {

    // Quick Test
    cout << fixed << setprecision(1) << static_cast<float>(strtod("2147483647", NULL)) << endl;
    cout << 100000.0 << endl;
    cout << 2147483647.0 << endl;
    cout << 2147483647.0f << endl;
    cout << static_cast<int>(atof("  42 ")) << endl;
    cout << static_cast<int>(atof("-0")) << endl;
    cout << static_cast<float>(2147483648) << endl;
    return 0;

    float fInfinity = 1.0f / 0.0f;
    double dInfinity = 1.0 / 0.0;

    float fMinusInfinity = log(0);
    double dMinusInfinity = log(0);

    float fNan = sqrt(-1);
    double dNan = sqrt(-1);

    cout << "===== values" << endl;
    cout << 42.424242 << endl;
    cout << 42.424242f << endl;
    cout << 1.00001 << endl;
    cout << 1.0000001 << endl;
    cout << 10000.1 << endl;
    cout << 1.23456789 << endl;
    cout << 12345678.9 << endl;

    cout << fInfinity << endl;
    cout << dInfinity << endl;
    cout << fMinusInfinity << endl;
    cout << dMinusInfinity << endl;
    cout << fNan << endl;
    cout << dNan << endl;

    cout << "===== isnan" << endl;
    cout << isnan(NAN) << endl;
    cout << isnan(fNan) << endl;
    cout << isnan(dNan) << endl;
    cout << isnan(INFINITY) << endl;
    cout << isnan(INFINITY) << endl;

    cout << "===== isfinite" << endl;
    cout << isfinite(NAN) << endl;
    cout << isfinite(fInfinity) << endl;
    cout << isfinite(dInfinity) << endl;
    cout << isfinite(fMinusInfinity) << endl;
    cout << isfinite(dMinusInfinity) << endl;
    cout << isfinite(fNan) << endl;
    cout << isfinite(dNan) << endl;

    cout << "===== isinf" << endl;
    cout << isinf(NAN) << endl;
    cout << isinf(fInfinity) << endl;
    cout << isinf(dInfinity) << endl;
    cout << isinf(fMinusInfinity) << endl;
    cout << isinf(dMinusInfinity) << endl;
    cout << isinf(fNan) << endl;
    cout << isinf(dNan) << endl;

    cout << "===== atof" << endl;
    cout << atof("0") << endl;
    cout << atof("0f") << endl;
    cout << atof("0.0f") << endl;
    cout << atof("inf") << endl;
    cout << atof("-inf") << endl;
    cout << atof("inff") << endl;
    cout << atof("-inff") << endl;
    cout << atof("nan") << endl;

    cout << atof("a") << endl;
    cout << atof("bbb") << endl;
    cout << atof(" ") << endl;

    cout << "===== arithmetic" << endl;
    cout << 2.0f + fInfinity << endl;
    cout << 2.0 + dInfinity << endl;
    cout << 4.0f / fInfinity << endl;
    cout << 4.0 + dInfinity << endl;

    cout << "===== comparison" << endl;
    cout << (dInfinity > INT_MAX) << endl;
    cout << (fInfinity > INT_MAX) << endl;
}
