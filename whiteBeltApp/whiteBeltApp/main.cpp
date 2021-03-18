#include <iostream>
#include <numeric>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <set>
#include <vector>
#include <map>
#include <exception>
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

    void Set(int numerator, int denominator) {
        p = numerator;
        q = denominator;
        validateFraction();
        reduceFraction();
    }

    void SetNumerator(const int& numerator) {
        p = numerator;
        validateFraction();
        reduceFraction();
    }

    void SetDenominator(const int& denominator) {
        q = denominator;
        validateFraction();
        reduceFraction();
    }

private:
    int p, q;

    void validateFraction() {
        if (q == 0) {
            throw invalid_argument("q = 0");
        }

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

Rational operator+(const Rational& lhs, const Rational& rhs) {
    int numerator = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
    int denominator = lhs.Denominator() * rhs.Denominator();
    return Rational(numerator, denominator);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    int numerator = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
    int denominator = lhs.Denominator() * rhs.Denominator();
    return Rational(numerator, denominator);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("/0");
    }
    int numerator = lhs.Numerator() * rhs.Denominator();
    int denominator = rhs.Numerator() * lhs.Denominator();
    return Rational(numerator, denominator);
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    int numerator = lhs.Numerator() * rhs.Numerator();
    int denominator = lhs.Denominator() * rhs.Denominator();
    return Rational(numerator, denominator);
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    Rational result = lhs - rhs;
    return (result.Numerator() == 0);
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    Rational result = lhs - rhs;
    return (result.Numerator() < 0);
}

bool is_stream_empty(istream& pFile)
{
    return pFile.peek() == istream::traits_type::eof();
}

istream& operator>>(istream& stream, Rational& rational) {   
    int numerator, denominator;    

    stream >> numerator;
    if (stream.peek() != '/')
        return stream;
    stream.ignore(1);
    if (stream.peek() == -1)
        return stream;
    stream >> denominator;
    if (denominator > 0)   
        rational.Set(numerator, denominator);        

    return stream;  
}

ostream& operator<<(ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

int main() {
    try {
                
        return 0;
    }
    catch (invalid_argument&) {
        cout << "Invalid argument";
    }
    catch (domain_error&) {
        cout << "Division by zero";
    }    

    return 0;
}
