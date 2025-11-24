#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNumber;
    string name;
    bool isOccupied;
    bool isDeleted;
    
    Student() : rollNumber(-1), name(""), isOccupied(false), isDeleted(false) {}
};

class StudentHashTable {
private:
    Student* table;
    int tableSize;
    
    int hashFunction(int rollNumber) {
        return rollNumber % tableSize;
    }
    
public:
    StudentHashTable() {
        tableSize = 15;
        table = new Student[tableSize];
    }
    
    void InsertRecord(int rollNumber, string name) {
        int index = hashFunction(rollNumber);
        int attempt = 0;
        int newIndex;
        
        while (attempt < tableSize) {
            newIndex = (index + attempt * attempt) % tableSize;
            
            if (!table[newIndex].isOccupied || table[newIndex].isDeleted) {
                table[newIndex].rollNumber = rollNumber;
                table[newIndex].name = name;
                table[newIndex].isOccupied = true;
                table[newIndex].isDeleted = false;
                cout << "Record inserted: Roll No. " << rollNumber << ", Name: " << name << endl;
                return;
            }
            
            if (table[newIndex].rollNumber == rollNumber) {
                cout << "Record with Roll No. " << rollNumber << " already exists" << endl;
                return;
            }
            
            attempt++;
        }
        
        cout << "Hash table is full, cannot insert record" << endl;
    }
    
    void SearchRecord(int rollNumber) {
        int index = hashFunction(rollNumber);
        int attempt = 0;
        int newIndex;
        
        while (attempt < tableSize) {
            newIndex = (index + attempt * attempt) % tableSize;
            
            if (!table[newIndex].isOccupied) {
                cout << "Record not found" << endl;
                return;
            }
            
            if (table[newIndex].rollNumber == rollNumber && !table[newIndex].isDeleted) {
                cout << "Record found: Roll No. " << rollNumber << ", Name: " << table[newIndex].name << endl;
                return;
            }
            
            attempt++;
        }
        
        cout << "Record not found" << endl;
    }
    
    void display() {
        cout << "\n--- Student Hash Table ---" << endl;
        for (int i = 0; i < tableSize; i++) {
            cout << "Index " << i << ": ";
            if (table[i].isOccupied && !table[i].isDeleted) {
                cout << "Roll No. " << table[i].rollNumber << ", Name: " << table[i].name;
            } else {
                cout << "Empty";
            }
            cout << endl;
        }
        cout << "--------------------------\n" << endl;
    }
    
    ~StudentHashTable() {
        delete[] table;
    }
};

int main() {
    StudentHashTable sht;
    
    sht.InsertRecord(101, "Alice");
    sht.InsertRecord(116, "Bob");
    sht.InsertRecord(131, "Charlie");
    sht.InsertRecord(146, "David");
    sht.InsertRecord(161, "Eve");
    
    sht.display();
    
    cout << "\nSearching for records:" << endl;
    sht.SearchRecord(116);
    sht.SearchRecord(150);
    sht.SearchRecord(101);
    
    return 0;
}