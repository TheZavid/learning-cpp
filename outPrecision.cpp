#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main () {
    ifstream file("input.txt", ifstream::in);

    float num;
    cout << fixed << setprecision(3);
    while (file >> num)
        cout << num << endl;
}