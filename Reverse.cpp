#include <vector>

using namespace std;

void Reverse(vector<int> &v) {
    vector<int> tmp;
    auto ti = tmp.begin();
    for (auto i: v)
        ti = tmp.insert(ti, i);
    v.clear();
    for (auto i: tmp)
        v.push_back(i);
}

vector<int> Reversed(const vector<int> &v) {
    vector<int> out = v;
    Reverse(out);
    return out;
}