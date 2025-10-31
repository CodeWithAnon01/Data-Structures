#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    int employeeID;
    int salary;
};

void mergeArrays(Employee staff[], int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    
    Employee* leftGroup = new Employee[leftSize];
    Employee* rightGroup = new Employee[rightSize];
    
    for (int i = 0; i < leftSize; i++)
        leftGroup[i] = staff[left + i];
    for (int j = 0; j < rightSize; j++)
        rightGroup[j] = staff[middle + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    while (i < leftSize && j < rightSize) {
        if (leftGroup[i].salary >= rightGroup[j].salary) {
            staff[k] = leftGroup[i];
            i++;
        } else {
            staff[k] = rightGroup[j];
            j++;
        }
        k++;
    }
    
    while (i < leftSize) {
        staff[k] = leftGroup[i];
        i++;
        k++;
    }
    
    while (j < rightSize) {
        staff[k] = rightGroup[j];
        j++;
        k++;
    }
    
    delete[] leftGroup;
    delete[] rightGroup;
}

void performMergeSort(Employee staff[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        
        performMergeSort(staff, left, middle);
        performMergeSort(staff, middle + 1, right);
        
        mergeArrays(staff, left, middle, right);
    }
}

void displayTopEmployees(Employee staff[], int total, int topCount) {
    cout << "\nTop " << topCount << " Highest-Paid Employees:\n";
    cout << "============================================\n";
    cout << "Rank\tName\t\tID\tSalary\n";
    cout << "============================================\n";
    
    for (int i = 0; i < topCount && i < total; i++) {
        cout << i + 1 << "\t" 
             << staff[i].name << "\t\t" 
             << staff[i].employeeID << "\t" 
             << staff[i].salary << endl;
    }
}

int main() {
    int totalEmployees = 12;
    Employee company[12];
    
    cout << "Enter records of " << totalEmployees << " employees:\n\n";
    
    for (int i = 0; i < totalEmployees; i++) {
        cout << "Employee " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> company[i].name;
        cout << "ID: ";
        cin >> company[i].employeeID;
        cout << "Salary: ";
        cin >> company[i].salary;
        cout << endl;
    }
    
    cout << "Sorting employees by salary (descending order)...\n";
    performMergeSort(company, 0, totalEmployees - 1);
    
    displayTopEmployees(company, totalEmployees, 3);
    
    return 0;
}