#include <iostream>
#include <vector>

using namespace std;

void printHeapArray(const vector<int>& heapArray) {
    for (int element : heapArray) {
        cout << element << " ";
    }
    cout << endl;
}

void calculateAndDisplayChildIndices(int parentIndex) {
    int leftChildIndex = 2 * parentIndex + 1;
    int rightChildIndex = 2 * parentIndex + 2;
    cout << "Parent index: " << parentIndex << endl;
    cout << "Left child index (2*" << parentIndex << "+1): " << leftChildIndex << endl;
    cout << "Right child index (2*" << parentIndex << "+2): " << rightChildIndex << endl;
}

vector<int> findNodesViolatingMaxHeapProperty(const vector<int>& dataArray) {
    vector<int> violatingNodeIndices;
    int totalElements = dataArray.size();

    for (int currentIndex = 0; currentIndex <= totalElements / 2 - 1; currentIndex++) {
        int leftChildIndex = 2 * currentIndex + 1;
        int rightChildIndex = 2 * currentIndex + 2;
        bool isViolating = false;

        if (leftChildIndex < totalElements && dataArray[currentIndex] < dataArray[leftChildIndex]) {
            isViolating = true;
        }
        if (rightChildIndex < totalElements && dataArray[currentIndex] < dataArray[rightChildIndex]) {
            isViolating = true;
        }
        if (isViolating) {
            violatingNodeIndices.push_back(currentIndex);
        }
    }
    return violatingNodeIndices;
}

bool checkMaxHeapProperty(const vector<int>& dataArray) {
    return findNodesViolatingMaxHeapProperty(dataArray).empty();
}

int main() {
    vector<int> sensorTemperatures = {15, 22, 18, 25, 10, 30, 12};

    cout << "Temperature data array: ";
    printHeapArray(sensorTemperatures);
    cout << endl;

    cout << "--- Part A: Child indices for element 22 (index 1) ---" << endl;
    calculateAndDisplayChildIndices(1);
    cout << "Left child value: " << sensorTemperatures[2 * 1 + 1]
         << ", Right child value: " << sensorTemperatures[2 * 1 + 2] << endl;
    cout << endl;

    cout << "--- Part B: Max-Heap property check ---" << endl;
    if (checkMaxHeapProperty(sensorTemperatures)) {
        cout << "The array satisfies the Max-Heap property." << endl;
    } else {
        cout << "The array does NOT satisfy the Max-Heap property." << endl;
        vector<int> violatingNodes = findNodesViolatingMaxHeapProperty(sensorTemperatures);
        cout << "Violating nodes:" << endl;
        for (int nodeIndex : violatingNodes) {
            cout << "  Index " << nodeIndex << " (value " << sensorTemperatures[nodeIndex]
                 << ") is smaller than at least one of its children." << endl;
            int leftChildIndex = 2 * nodeIndex + 1;
            int rightChildIndex = 2 * nodeIndex + 2;
            if (leftChildIndex < (int)sensorTemperatures.size()) {
                cout << "    Left child: index " << leftChildIndex << " (value " << sensorTemperatures[leftChildIndex] << ")" << endl;
            }
            if (rightChildIndex < (int)sensorTemperatures.size()) {
                cout << "    Right child: index " << rightChildIndex << " (value " << sensorTemperatures[rightChildIndex] << ")" << endl;
            }
        }
    }
    cout << endl;

    cout << "--- Part C: Min-Heap vs Max-Heap ---" << endl;
    cout << "To find the minimum temperature instead of the maximum:" << endl;
    cout << "Build a Min-Heap where every parent node is SMALLER than its children." << endl;
    cout << "The heapify comparison flips: swap parent with the SMALLEST child" << endl;
    cout << "instead of the largest. The minimum value will then reside at the root." << endl;

    return 0;
}
