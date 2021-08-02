#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
    ifstream file("input.txt", ifstream::in);

    float num;
    while (file >> num)
        out << num << endl;
    out.close();
}