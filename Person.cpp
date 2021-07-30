#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

struct PersonData {
    string name;
    string lastName;
};

string GetHistory (const vector<string>& v) {
    string out = v[0];
    int inserted = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == v[i-1]) continue;
        if (inserted == 0)
            out += " (" + v[i];
        else
            out += ", " + v[i];
        inserted++;
    }
    if (inserted > 0)
        out += ")";
    return out;
}

class Person {
public:
    Person (const string& name, const string& lastName, int year) {
        birthYear = year;
        data[birthYear] = {name, lastName}; 
    }
    void ChangeFirstName(int year, const string& name) {
        if (year >= birthYear)
            data[year].name = name;
    }
    void ChangeLastName(int year, const string& lastName) {
        if (year >= birthYear)
            data[year].lastName = lastName;
    }
    string GetFullName(int year)  const {
        if (year < birthYear)
            return "No person";
        PersonData pd;
        for (const auto& rec: data) {
            if (rec.first > year) break;
            if (rec.second.name.size() > 0) pd.name = rec.second.name;
            if (rec.second.lastName.size() > 0) pd.lastName = rec.second.lastName;
        }
        if (pd.name.size() > 0 && pd.lastName.size() > 0)
            return pd.name + " " + pd.lastName;
        if (pd.name.size() > 0 && pd.lastName.size() == 0)
            return pd.name + " with unknown last name";
        if (pd.name.size() == 0 && pd.lastName.size() > 0)
            return pd.lastName + " with unknown first name";
        return "Incognito";
    }
    string GetFullNameWithHistory(int year) const {
        if (year < birthYear)
            return "No person";
        vector<string> names;
        vector<string> lastNames;
        for (const auto& rec: data) {
            if (rec.first > year) break;
            if (rec.second.name.size() > 0) names.insert(names.begin(), rec.second.name);
            if (rec.second.lastName.size() > 0) lastNames.insert(lastNames.begin(), rec.second.lastName);
        }
        if (names.size() > 0 && lastNames.size() > 0)
            return GetHistory(names) + " " + GetHistory(lastNames);
        if (names.size() > 0 && lastNames.size() == 0)
            return GetHistory(names) + " with unknown last name";
        if (names.size() == 0 && lastNames.size() > 0)
            return GetHistory(lastNames) + " with unknown first name";
        return "Incognito";
    }
private:
  map<int, PersonData> data;
  int birthYear;
};

