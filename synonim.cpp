#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main () {
    string out;
    map<string, set<string> > m;
    int q;
    cin >> q;
    for (int i=0; i < q; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "ADD") {
            string w1, w2;
            cin >> w1 >> w2;
            m[w1].insert(w2);
            m[w2].insert(w1);
        }
        else
        if (cmd == "COUNT") {
            string w;
            cin >> w;
            out += to_string(m[w].size()) + "\n";
        }
        else
        if (cmd == "CHECK") {
            string w1, w2;
            cin >> w1 >> w2;
            if (m[w1].count(w2))
                out += "YES\n";
            else
                out += "NO\n";
        }
    }
    cout << out;
}