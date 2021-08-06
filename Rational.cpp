#include <iostream>
#include <sstream>
#include <numeric>
#include <ctype.h>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Rational {
public:
    Rational() {
        num = 0;
        denum = 1;
    }

    Rational(int numerator, int denominator) {
        if (numerator == 0) {
            num = 0;
            denum = 1;
            return;
        }
        int sign = 1;
        if (numerator < 0) {
            numerator *= -1;
            sign *= -1;
        }
        if (denominator < 0) {
            denominator *= -1;
            sign *= -1;
        }
        int d = gcd(numerator, denominator);
        num = sign * (numerator/d);
        denum = denominator/d;
    }

    int Numerator() const {
        return num;
    }

    int Denominator() const {
        return denum;
    }

private:
    int num;
    int denum;
};

istream& operator>>(istream& in, Rational& r) {
    int n;
    int d;
    char peek;
    peek = in.peek();
    in >> n;
    char delim;
    in >> delim;
    if (delim != '/')
        return in;
    if (!isdigit(in.peek()))
        return in;
    in >> d;
    if (peek != EOF)
        r = Rational(n, d);
    return in;
}

ostream& operator<<(ostream& out, Rational r) {
    out << r.Numerator() << '/' << r.Denominator();
    return out;
}

Rational operator+(const Rational& x, const Rational& y) {
    if (x.Denominator() != y.Denominator()) {
        int m = lcm(x.Denominator(), y.Denominator());
        int xt = m / x.Denominator();
        int yt = m / y.Denominator();
        return Rational((x.Numerator() * xt) + (y.Numerator() * yt), m);
    } else
        return Rational(x.Numerator() + y.Numerator(), x.Denominator());
}

Rational operator-(const Rational& x, const Rational& y) {
    return x + Rational(y.Numerator() * -1, y.Denominator());
}

bool operator==(const Rational& x, const Rational& y) {
    return (x.Numerator() * y.Denominator()) == (y.Numerator() * x.Denominator());
}

Rational operator*(const Rational& x, const Rational& y) {
    return Rational(x.Numerator() * y.Numerator(), x.Denominator() * y.Denominator());
}

Rational operator/(const Rational& x, const Rational& y) {
    return x * Rational(y.Denominator(), y.Numerator());
}

bool operator<(const Rational& x, const Rational& y) {
    return (x.Numerator() * y.Denominator()) < (y.Numerator() * x.Denominator());
}

bool operator>(const Rational& x, const Rational& y) {
    return (x.Numerator() * y.Denominator()) > (y.Numerator() * x.Denominator());
}
