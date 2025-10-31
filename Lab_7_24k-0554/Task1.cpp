#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int score;
    Student* next;
    
    Student(string n, int s) : name(n), score(s), next(nullptr) {}
};

class StudentList {
private:
    Student* head;
    
    int findMaxScore() {
        int maximum = 0;
        Student* current = head;
        while (current != nullptr) {
            if (current->score > maximum)
                maximum = current->score;
            current = current->next;
        }
        return maximum;
    }
    
    void sortByDigit(int digitPlace) {
        Student* buckets[10] = {nullptr};
        Student* bucketEnds[10] = {nullptr};
        
        Student* student = head;
        while (student != nullptr) {
            Student* nextStudent = student->next;
            int digit = (student->score / digitPlace) % 10;
            
            student->next = nullptr;
            
            if (buckets[digit] == nullptr) {
                buckets[digit] = student;
                bucketEnds[digit] = student;
            } else {
                bucketEnds[digit]->next = student;
                bucketEnds[digit] = student;
            }
            
            student = nextStudent;
        }
        
        head = nullptr;
        Student* lastStudent = nullptr;
        
        for (int i = 0; i < 10; i++) {
            if (buckets[i] != nullptr) {
                if (head == nullptr) {
                    head = buckets[i];
                    lastStudent = bucketEnds[i];
                } else {
                    lastStudent->next = buckets[i];
                    lastStudent = bucketEnds[i];
                }
            }
        }
    }
    
public:
    StudentList() : head(nullptr) {}
    
    void insertStudent(string studentName, int testScore) {
        Student* newStudent = new Student(studentName, testScore);
        if (head == nullptr) {
            head = newStudent;
        } else {
            Student* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newStudent;
        }
    }
    
    void performRadixSort() {
        int maxScore = findMaxScore();
        
        for (int place = 1; maxScore / place > 0; place *= 10) {
            sortByDigit(place);
        }
    }
    
    void displayStudents() {
        cout << "\nSorted Student Records:\n";
        cout << "------------------------\n";
        Student* current = head;
        while (current != nullptr) {
            cout << current->name << "\t\t" << current->score << endl;
            current = current->next;
        }
    }
    
    ~StudentList() {
        Student* current = head;
        while (current != nullptr) {
            Student* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    StudentList records;
    int numberOfStudents;
    
    cout << "Enter number of students: ";
    cin >> numberOfStudents;
    
    for (int i = 1; i <= numberOfStudents; i++) {
        string studentName;
        int testScore;
        
        cout << "Enter name of student " << i << ": ";
        cin >> studentName;
        cout << "Enter test score: ";
        cin >> testScore;
        
        records.insertStudent(studentName, testScore);
    }
    
    cout << "\nSorting student records using Radix Sort...\n";
    records.performRadixSort();
    records.displayStudents();
    
    return 0;
}