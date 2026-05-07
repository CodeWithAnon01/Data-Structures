#include <iostream>
#include <vector>

using namespace std;

void printHeapArray(const vector<int>& heapArray) {
    for (int element : heapArray) {
        cout << element << " ";
    }
    cout << endl;
}

void swapElements(int& firstElement, int& secondElement) {
    int temporaryStorage = firstElement;
    firstElement = secondElement;
    secondElement = temporaryStorage;
}

void minHeapifyUp(vector<int>& heapArray, int currentIndex) {
    int parentIndex = (currentIndex - 1) / 2;
    if (currentIndex > 0 && heapArray[currentIndex] < heapArray[parentIndex]) {
        cout << "Swapping " << heapArray[currentIndex] << " (index " << currentIndex
             << ") with parent " << heapArray[parentIndex] << " (index " << parentIndex << ")" << endl;
        swapElements(heapArray[currentIndex], heapArray[parentIndex]);
        cout << "Heap state: ";
        printHeapArray(heapArray);
        minHeapifyUp(heapArray, parentIndex);
    }
}

void insertIntoMinHeap(vector<int>& heapArray, int newPatientPriority) {
    heapArray.push_back(newPatientPriority);
    int insertedIndex = heapArray.size() - 1;
    cout << "Inserted " << newPatientPriority << " at index " << insertedIndex << endl;
    cout << "Heap state: ";
    printHeapArray(heapArray);
    minHeapifyUp(heapArray, insertedIndex);
}

int main() {
    vector<int> patientPriorities = {3, 5, 8, 10, 7, 12, 9};

    cout << "Initial Min-Heap: ";
    printHeapArray(patientPriorities);
    cout << endl;

    cout << "--- Inserting patient with Priority 2 ---" << endl;
    insertIntoMinHeap(patientPriorities, 2);
    cout << "Min-Heap after insertion: ";
    printHeapArray(patientPriorities);
    cout << "Root: " << patientPriorities[0] << endl;
    cout << endl;

    cout << "--- Inserting patient with Priority 1 ---" << endl;
    insertIntoMinHeap(patientPriorities, 1);
    cout << "Min-Heap after insertion: ";
    printHeapArray(patientPriorities);
    cout << "Root: " << patientPriorities[0] << endl;
    cout << "Priority 1 is at the root because it is the most urgent case." << endl;

    return 0;
}
