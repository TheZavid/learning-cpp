#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    double d = b*b - (4*a*c);
    if (d < 0) return 0;
    if (a == 0) {
        if (b != 0) cout << -c/b;
        return 0;
    }
    b = -b;
    a = 2*a;
    if (d == 0) {
        if ( b != 0) cout << b/a;
        else cout << 0;
    }
    else
        cout << (b + sqrt(d))/a << ' ' << (b - sqrt(d))/a;
}