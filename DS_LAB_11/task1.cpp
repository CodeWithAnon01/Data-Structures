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

void maxHeapifyDown(vector<int>& heapArray, int totalElements, int currentIndex) {
    int largestElementIndex = currentIndex;
    int leftChildIndex = 2 * currentIndex + 1;
    int rightChildIndex = 2 * currentIndex + 2;

    if (leftChildIndex < totalElements && heapArray[leftChildIndex] > heapArray[largestElementIndex]) {
        largestElementIndex = leftChildIndex;
    }

    if (rightChildIndex < totalElements && heapArray[rightChildIndex] > heapArray[largestElementIndex]) {
        largestElementIndex = rightChildIndex;
    }

    if (largestElementIndex != currentIndex) {
        cout << "Swapping " << heapArray[currentIndex] << " with " << heapArray[largestElementIndex] << endl;
        swapElements(heapArray[currentIndex], heapArray[largestElementIndex]);
        cout << "Heap state: ";
        printHeapArray(heapArray);
        maxHeapifyDown(heapArray, totalElements, largestElementIndex);
    }
}

void buildMaxHeapFromArray(vector<int>& taskPriorities) {
    int totalElements = taskPriorities.size();
    int lastNonLeafNodeIndex = totalElements / 2 - 1;

    cout << "Starting Max-Heap construction from index " << lastNonLeafNodeIndex << endl;
    cout << "Initial array: ";
    printHeapArray(taskPriorities);
    cout << endl;

    for (int currentIndex = lastNonLeafNodeIndex; currentIndex >= 0; currentIndex--) {
        cout << "Heapifying at index " << currentIndex << " (value " << taskPriorities[currentIndex] << "):" << endl;
        maxHeapifyDown(taskPriorities, totalElements, currentIndex);
    }
}

int main() {
    vector<int> taskPriorities = {10, 20, 15, 30, 40, 5, 25};

    buildMaxHeapFromArray(taskPriorities);

    cout << endl << "Final Max-Heap: ";
    printHeapArray(taskPriorities);

    cout << endl << "Root node: " << taskPriorities[0] << endl;
    cout << "The root represents the highest priority because in a Max-Heap," << endl;
    cout << "every parent node is greater than or equal to its children," << endl;
    cout << "so the maximum value always bubbles up to the root." << endl;

    return 0;
}
