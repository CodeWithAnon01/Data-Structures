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

void maxHeapifyUp(vector<int>& heapArray, int currentIndex) {
    int parentIndex = (currentIndex - 1) / 2;
    if (currentIndex > 0 && heapArray[currentIndex] > heapArray[parentIndex]) {
        cout << "Swapping " << heapArray[currentIndex] << " (index " << currentIndex
             << ") with parent " << heapArray[parentIndex] << " (index " << parentIndex << ")" << endl;
        swapElements(heapArray[currentIndex], heapArray[parentIndex]);
        cout << "Heap state: ";
        printHeapArray(heapArray);
        maxHeapifyUp(heapArray, parentIndex);
    }
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
        swapElements(heapArray[currentIndex], heapArray[largestElementIndex]);
        maxHeapifyDown(heapArray, totalElements, largestElementIndex);
    }
}

void updatePlayerScore(vector<int>& heapArray, int playerIndex, int newScoreValue) {
    int previousScoreValue = heapArray[playerIndex];
    cout << "Updating index " << playerIndex << " from " << previousScoreValue << " to " << newScoreValue << endl;
    heapArray[playerIndex] = newScoreValue;

    if (newScoreValue > previousScoreValue) {
        cout << "Value increased, using Heapify Up to restore Max-Heap property." << endl;
        maxHeapifyUp(heapArray, playerIndex);
    } else {
        cout << "Value decreased, using Heapify Down to restore Max-Heap property." << endl;
        maxHeapifyDown(heapArray, heapArray.size(), playerIndex);
    }
}

void printTreeStructure(const vector<int>& heapArray, int currentIndex, string indentation, bool isLastChild) {
    if (currentIndex >= (int)heapArray.size()) return;
    cout << indentation;
    if (isLastChild) {
        cout << "└── ";
        indentation += "    ";
    } else {
        cout << "├── ";
        indentation += "│   ";
    }
    cout << heapArray[currentIndex] << endl;

    int leftChildIndex = 2 * currentIndex + 1;
    int rightChildIndex = 2 * currentIndex + 2;
    bool hasLeftChild = leftChildIndex < (int)heapArray.size();
    bool hasRightChild = rightChildIndex < (int)heapArray.size();

    if (hasLeftChild) printTreeStructure(heapArray, leftChildIndex, indentation, !hasRightChild);
    if (hasRightChild) printTreeStructure(heapArray, rightChildIndex, indentation, true);
}

bool verifyCompleteBinaryTree(const vector<int>& heapArray) {
    int totalElements = heapArray.size();
    for (int currentIndex = 0; currentIndex < totalElements; currentIndex++) {
        int leftChildIndex = 2 * currentIndex + 1;
        int rightChildIndex = 2 * currentIndex + 2;
        if (leftChildIndex >= totalElements && rightChildIndex < totalElements) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> leaderboardScores = {500, 450, 400, 300, 200, 350, 150};

    cout << "Initial Leaderboard (Max-Heap): ";
    printHeapArray(leaderboardScores);
    cout << endl;

    updatePlayerScore(leaderboardScores, 3, 550);

    cout << endl << "Final Leaderboard: ";
    printHeapArray(leaderboardScores);

    cout << endl << "Tree Structure:" << endl;
    printTreeStructure(leaderboardScores, 0, "", true);

    cout << endl << "Is complete binary tree: " << (verifyCompleteBinaryTree(leaderboardScores) ? "Yes" : "No") << endl;

    return 0;
}
