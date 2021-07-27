#include <iostream>
#include <string>
#include <set>

using namespace std;

int main () {
    int q;
    cin >> q;
    set<string> uniq;
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        uniq.insert(s);
    }
    cout << uniq.size() << endl;
}