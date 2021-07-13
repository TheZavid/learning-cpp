#include <iostream>
#include <string>

using namespace std;

int main () {
    string in;
    cin >> in;
    int f = -2;
    for (int i = 0; i <= in.size(); i++)
        if (in[i] == 'f') 
            if (!(f > 0) && f++ == -1) f = i;
    cout << f;
}