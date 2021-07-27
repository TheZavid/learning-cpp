#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toLower(string s) {
    string out;
    for (const auto& c: s)
        out += tolower(c);
    return out;
}

int main () {
    int n;
    cin >> n;
    vector<string> a;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end(), [](string x, string y) -> bool {
        return toLower(x) < toLower(y);
    });
    for (const auto& i: a)
        cout << i << " ";
}