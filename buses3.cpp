#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main () {
    map<set<string>, int> m;
    string out;
    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        set<string>  cur_s;
        int qb;
        cin >> qb;
        for (int j=0; j<qb; j++) {
            string s;
            cin >> s;
            cur_s.insert(s);
        }
        if (m[cur_s] > 0)
            out += "Already exists for " + to_string(m[cur_s]) + "\n";
        else {
            m[cur_s] = m.size();
            out += "New bus " + to_string(m.size()) + "\n";
        }
    }
    cout << out;
}