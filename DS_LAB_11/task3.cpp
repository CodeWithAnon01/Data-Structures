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

    if (leftChildIndex < totalElements) {
        cout << "Comparing index " << currentIndex << " (" << heapArray[currentIndex]
             << ") with left child index " << leftChildIndex << " (" << heapArray[leftChildIndex] << ")" << endl;
    }
    if (leftChildIndex < totalElements && heapArray[leftChildIndex] > heapArray[largestElementIndex]) {
        largestElementIndex = leftChildIndex;
    }

    if (rightChildIndex < totalElements) {
        cout << "Comparing index " << currentIndex << " (" << heapArray[currentIndex]
             << ") with right child index " << rightChildIndex << " (" << heapArray[rightChildIndex] << ")" << endl;
    }
    if (rightChildIndex < totalElements && heapArray[rightChildIndex] > heapArray[largestElementIndex]) {
        largestElementIndex = rightChildIndex;
    }

    if (largestElementIndex != currentIndex) {
        cout << "Largest is " << heapArray[largestElementIndex] << " at index " << largestElementIndex
             << ". Swapping with " << heapArray[currentIndex] << " at index " << currentIndex << endl;
        swapElements(heapArray[currentIndex], heapArray[largestElementIndex]);
        cout << "Heap state: ";
        printHeapArray(heapArray);
        maxHeapifyDown(heapArray, totalElements, largestElementIndex);
    } else {
        cout << "No swap needed at index " << currentIndex << endl;
    }
}

int extractMaxFromPriorityQueue(vector<int>& heapArray) {
    int highestPriorityValue = heapArray[0];

    cout << "Removing root: " << highestPriorityValue << endl;
    cout << "Replacing root with last element: " << heapArray.back() << endl;

    heapArray[0] = heapArray.back();
    heapArray.pop_back();

    cout << "Heap after replacement: ";
    printHeapArray(heapArray);
    cout << endl;

    cout << "--- Performing Heapify Down ---" << endl;
    maxHeapifyDown(heapArray, heapArray.size(), 0);

    return highestPriorityValue;
}

int main() {
    vector<int> packagePriorities = {50, 40, 35, 20, 30, 10, 25};

    cout << "Initial Max-Heap (Priority Queue): ";
    printHeapArray(packagePriorities);
    cout << endl;

    int removedPriority = extractMaxFromPriorityQueue(packagePriorities);

    cout << endl << "Removed package priority: " << removedPriority << endl;
    cout << "Final heap: ";
    printHeapArray(packagePriorities);
    cout << "New peek value: " << packagePriorities[0] << endl;

    return 0;
}
