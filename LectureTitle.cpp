#include <string>

using namespace std;

struct Specialization {
    string data;
    explicit Specialization(string s) {
        data = s;
    }
};

struct Course {
    string data;
    explicit Course(string s) {
        data = s;
    }
};

struct Week {
    string data;
    explicit Week(string s) {
        data = s;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
    explicit LectureTitle( Specialization s, Course c, Week w) {
        specialization = s.data;
        course = c.data;
        week = w.data;
    }
};