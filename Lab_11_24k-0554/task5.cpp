#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    bool isOccupied;
    bool isDeleted;
    
    Employee() : name(""), isOccupied(false), isDeleted(false) {}
};

class EmployeeHashTable {
private:
    Employee* table;
    int tableSize;
    
    int hash1(string name) {
        int sum = 0;
        for (char c : name) {
            sum += int(c);
        }
        return sum % tableSize;
    }
    
    int hash2(string name) {
        int sum = 0;
        for (char c : name) {
            sum += int(c);
        }
        return 7 - (sum % 7);
    }
    
public:
    EmployeeHashTable() {
        tableSize = 50;
        table = new Employee[tableSize];
    }
    
    void Add_Employee(string name) {
        int h1 = hash1(name);
        int h2 = hash2(name);
        int index = h1;
        int i = 1;
        
        while (table[index].isOccupied && !table[index].isDeleted) {
            if (table[index].name == name) {
                cout << "Employee '" << name << "' already exists" << endl;
                return;
            }
            index = (h1 + i * h2) % tableSize;
            i++;
            
            if (i >= tableSize) {
                cout << "Hash table is full" << endl;
                return;
            }
        }
        
        table[index].name = name;
        table[index].isOccupied = true;
        table[index].isDeleted = false;
        cout << "Employee '" << name << "' added successfully at index " << index << endl;
    }
    
    void Search_Employee(string name) {
        int h1 = hash1(name);
        int h2 = hash2(name);
        int index = h1;
        int i = 1;
        
        while (table[index].isOccupied || table[index].isDeleted) {
            if (table[index].isOccupied && !table[index].isDeleted && table[index].name == name) {
                cout << "Employee '" << name << "' found at index " << index << endl;
                return;
            }
            
            index = (h1 + i * h2) % tableSize;
            i++;
            
            if (i >= tableSize) {
                break;
            }
        }
        
        cout << "Employee not found in the directory." << endl;
    }
    
    void Display_Table() {
        cout << "\n--- Employee Directory ---" << endl;
        bool hasEmployees = false;
        
        for (int i = 0; i < tableSize; i++) {
            if (table[i].isOccupied && !table[i].isDeleted) {
                cout << "Index " << i << ": " << table[i].name << endl;
                hasEmployees = true;
            }
        }
        
        if (!hasEmployees) {
            cout << "No employees in directory" << endl;
        }
        cout << "--------------------------\n" << endl;
    }
    
    ~EmployeeHashTable() {
        delete[] table;
    }
};

int main() {
    EmployeeHashTable empTable;
    
    empTable.Add_Employee("John Smith");
    empTable.Add_Employee("Sarah Johnson");
    empTable.Add_Employee("Michael Brown");
    empTable.Add_Employee("Emily Davis");
    empTable.Add_Employee("David Wilson");
    
    empTable.Display_Table();
    
    cout << "\nSearching for employees:" << endl;
    empTable.Search_Employee("Sarah Johnson");
    empTable.Search_Employee("Robert Taylor");
    empTable.Search_Employee("David Wilson");
    
    return 0;
}