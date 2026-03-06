#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNum;
    string name;
    string dept;
    Student* next;
};

Student* head = nullptr;

void addStudent(int roll, string nm, string dep) {
    Student* newS = new Student();
    newS->rollNum = roll;
    newS->name = nm;
    newS->dept = dep;
    newS->next = nullptr;

    if (!head) {
        head = newS;
        return;
    }
    Student* tmp = head;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = newS;
}

void deleteByRoll(int roll) {
    if (!head) {
        cout << "list empty" << endl;
        return;
    }
    if (head->rollNum == roll) {
        Student* tmp = head;
        head = head->next;
        delete tmp;
        cout << "deleted roll " << roll << endl;
        return;
    }
    Student* curr = head;
    while (curr->next && curr->next->rollNum != roll)
        curr = curr->next;
    if (!curr->next) {
        cout << "roll " << roll << " not found" << endl;
        return;
    }
    Student* toRemove = curr->next;
    curr->next = toRemove->next;
    delete toRemove;
    cout << "deleted roll " << roll << endl;
}

void showAll() {
    if (!head) {
        cout << "no students registered" << endl;
        return;
    }
    Student* tmp = head;
    cout << "registered students:" << endl;
    while (tmp) {
        cout << "Roll: " << tmp->rollNum << " | Name: " << tmp->name << " | Dept: " << tmp->dept << endl;
        tmp = tmp->next;
    }
}

int main() {
    addStudent(101, "Ahmed", "CS");
    addStudent(102, "Sara", "EE");
    addStudent(103, "Bilal", "ME");

    showAll();

    deleteByRoll(102);
    cout << "\nafter deleting roll 102:" << endl;
    showAll();

    deleteByRoll(999);

    return 0;
}
