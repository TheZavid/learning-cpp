#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
    ifstream file("input.txt", ifstream::in);

    string line;
    while (getline(file, line))
        cout << line << endl;
}