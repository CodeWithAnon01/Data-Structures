#include <iostream>
#include <cstring>
using namespace std;

class Exam {
public:
    char* stuName;
    char* examDate;
    int score;

    Exam(const char* name, const char* date, int sc) {
        stuName = new char[strlen(name) + 1];
        strcpy(stuName, name);
        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);
        score = sc;
    }

    ~Exam() {
        delete[] stuName;
        delete[] examDate;
    }

    void setScore(int sc) {
        score = sc;
    }

    void display() {
        cout << "Name: " << stuName << endl;
        cout << "Date: " << examDate << endl;
        cout << "Score: " << score << endl;
    }
};

int main() {
    Exam e1("Ali", "2024-01-15", 85);
    cout << "Original exam:" << endl;
    e1.display();

    Exam e2 = e1;
    cout << "\nShallow copy exam:" << endl;
    e2.display();

    e2.setScore(95);
    cout << "\nAfter changing score in e2:" << endl;
    cout << "e2 score: " << e2.score << endl;
    cout << "e1 score: " << e1.score << endl;

    cout << "\nboth point to same mem, deleting e2 will cause issues when e1 destructs" << endl;

    return 0;
}
