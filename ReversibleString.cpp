#include <string>
#include <vector>

using namespace std;

class ReversibleString
{
public:
    ReversibleString () {}
    ReversibleString (const string& s) {
        for (int i = 0; i < s.size(); i++)
            vString.push_back(s[i]);
    }
    void Reverse () {
        reversed = !reversed;
    }
    string ToString() const{
        string out;
        if (reversed) {
            for (int i = vString.size() - 1; i >= 0; i--)
                out += vString[i];
        } else {
            for (int i = 0; i < vString.size(); i++)
                out += vString[i];
        }
        return out;
    }
private:
    vector<char> vString;
    bool reversed = false; 
};