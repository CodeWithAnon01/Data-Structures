#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int comparisonCounter = 0;

void swapElements(int &first, int &second) {
    int temp = first;
    first = second;
    second = temp;
}

int selectFirstPivot(int arr[], int start, int end) {
    return start;
}

int selectRandomPivot(int arr[], int start, int end) {
    int randomIndex = start + rand() % (end - start + 1);
    swapElements(arr[randomIndex], arr[end]);
    return end;
}

int selectMiddlePivot(int arr[], int start, int end) {
    int middle = start + (end - start) / 2;
    swapElements(arr[middle], arr[end]);
    return end;
}

int selectMedianOfThree(int arr[], int start, int end) {
    int middle = start + (end - start) / 2;
    
    if (arr[start] > arr[middle])
        swapElements(arr[start], arr[middle]);
    if (arr[start] > arr[end])
        swapElements(arr[start], arr[end]);
    if (arr[middle] > arr[end])
        swapElements(arr[middle], arr[end]);
    
    swapElements(arr[middle], arr[end]);
    return end;
}

int partitionArray(int arr[], int start, int end, int pivotIndex) {
    int pivotValue = arr[pivotIndex];
    int boundary = start - 1;
    
    for (int current = start; current < end; current++) {
        comparisonCounter++;
        if (arr[current] <= pivotValue) {
            boundary++;
            swapElements(arr[boundary], arr[current]);
        }
    }
    
    swapElements(arr[boundary + 1], arr[end]);
    return boundary + 1;
}

void performQuickSort(int arr[], int start, int end, int (*choosePivot)(int[], int, int)) {
    if (start < end) {
        int pivotIndex = choosePivot(arr, start, end);
        int partitionPoint = partitionArray(arr, start, end, pivotIndex);
        
        performQuickSort(arr, start, partitionPoint - 1, choosePivot);
        performQuickSort(arr, partitionPoint + 1, end, choosePivot);
    }
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copyArray(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

int main() {
    srand(time(0));
    
    int original[] = {10, 7, 8, 9, 1, 5, 3};
    int size = 7;
    int working[7];
    
    cout << "Original array: ";
    displayArray(original, size);
    cout << "\n========================================\n\n";
    
    cout << "1. FIRST ELEMENT AS PIVOT:\n";
    copyArray(original, working, size);
    comparisonCounter = 0;
    performQuickSort(working, 0, size - 1, selectFirstPivot);
    cout << "Sorted array: ";
    displayArray(working, size);
    cout << "Total comparisons: " << comparisonCounter << endl;
    cout << "\n========================================\n\n";
    
    cout << "2. RANDOM ELEMENT AS PIVOT:\n";
    copyArray(original, working, size);
    comparisonCounter = 0;
    performQuickSort(working, 0, size - 1, selectRandomPivot);
    cout << "Sorted array: ";
    displayArray(working, size);
    cout << "Total comparisons: " << comparisonCounter << endl;
    cout << "\n========================================\n\n";
    
    cout << "3. MIDDLE ELEMENT AS PIVOT:\n";
    copyArray(original, working, size);
    comparisonCounter = 0;
    performQuickSort(working, 0, size - 1, selectMiddlePivot);
    cout << "Sorted array: ";
    displayArray(working, size);
    cout << "Total comparisons: " << comparisonCounter << endl;
    cout << "\n========================================\n\n";
    
    cout << "4. MEDIAN OF THREE AS PIVOT:\n";
    copyArray(original, working, size);
    comparisonCounter = 0;
    performQuickSort(working, 0, size - 1, selectMedianOfThree);
    cout << "Sorted array: ";
    displayArray(working, size);
    cout << "Total comparisons: " << comparisonCounter << endl;
    cout << "\n========================================\n\n";
    
    cout << "EFFICIENCY ANALYSIS:\n";
    cout << "- Median of three typically provides best performance\n";
    cout << "- Random pivot helps avoid worst case scenarios\n";
    cout << "- First element pivot can be worst for sorted data\n";
    cout << "- Middle element is a good compromise\n";
    
    return 0;
}