#include <string>
#include <vector>

using namespace std;

bool IsPalindrom (string s) {
    string ns;
    for (auto c: s)
        ns = c + ns;
    return s == ns;
}

vector<string> PalindromFilter(vector<string> in, int minl) {
    vector<string> out;
    for (auto s: in)
        if (IsPalindrom(s) && s.size() >= minl) out.push_back(s);
    return out;
}
