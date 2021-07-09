#include <iostream>
#include <string>

using namespace std;

int main () {
    string one, two, three;
    cin >> one >> two >> three;
    string best = one;
    if (two < best) best = two;
    if (three < best) best = three;
    cout << best;
}