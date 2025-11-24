#include <iostream>
using namespace std;

class Exam {
private:
    int* marks;
    
public:
    Exam(int m) {
        marks = new int;
        *marks = m;
        cout << "Constructor called: marks = " << *marks << endl;
    }
    
    ~Exam() {
        cout << "Destructor called for marks = " << *marks << endl;
        delete marks;
    }
    
    void setMarks(int m) {
        *marks = m;
    }
    
    int getMarks() const {
        return *marks;
    }
    
    void display() const {
        cout << "Marks: " << *marks << " (Address: " << marks << ")" << endl;
    }
};

int main() {
    cout << "=== a) Creating exam1 object ===" << endl;
    Exam exam1(85);
    exam1.display();
    
    cout << "\n=== b) Copying exam1 into exam2 (Shallow Copy) ===" << endl;
    Exam exam2 = exam1;
    exam2.display();
    
    cout << "\n=== Demonstrating Shallow Copy Issue ===" << endl;
    cout << "Both objects point to the SAME memory location!" << endl;
    cout << "Exam1: ";
    exam1.display();
    cout << "Exam2: ";
    exam2.display();
    
    cout << "\n=== c) Changing marks in exam2 ===" << endl;
    exam2.setMarks(95);
    
    cout << "\nAfter modification:" << endl;
    cout << "Exam1: ";
    exam1.display();
    cout << "Exam2: ";
    exam2.display();
    
    cout << "\n*** SHALLOW COPY ISSUE OBSERVED ***" << endl;
    cout << "Changing exam2 also changed exam1!" << endl;
    cout << "Both share the same memory address for marks pointer." << endl;
    
    cout << "\n=== Program ending ===" << endl;
    cout << "WARNING: This will cause DOUBLE DELETION error!" << endl;
    cout << "Both destructors will try to delete the same memory." << endl;
    
    return 0;
}