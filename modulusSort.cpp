#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end(), [](int x, int y) -> bool {
        if (x < 0) x = -x;
        if (y < 0) y = -y;
        return x < y;
    });
    for (const auto& i: a)
        cout << i << " ";
}