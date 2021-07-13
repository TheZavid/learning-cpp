#include <iostream>
#include <string>

using namespace std;

int main () {
    string out = "";
    int in;
    cin >> in;
    while (in != 0){
        out=(in%2==0 ?"0":"1")+out;
        in/=2;
    }
    cout << out;
}