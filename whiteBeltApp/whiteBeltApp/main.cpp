#include <iostream>
#include <numeric>
using namespace std;

class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
        reduceFraction();
    }

    Rational(int numerator, int denominator) {
        p = numerator;
        q = denominator;
        validateFraction();
        reduceFraction();
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }

private:
    int p, q;

    void validateFraction() {
        if (p * q > 0) {
            p = abs(p);
            q = abs(q);
        }
        if (q < 0 && p > 0) {
            p = -1 * p;
            q = abs(q);
        }
        if (p == 0) {
            q = 1;
        }
    }

    void reduceFraction() {
        int GCD = 0;
        while (GCD != 1) {
            GCD = gcd(p, q);
            p /= GCD;
            q /= GCD;
        }
    }
};

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
