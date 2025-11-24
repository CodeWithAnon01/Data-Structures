#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubbleSort(int arr[], int n, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n, int &comparisons) {
    comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

void shellSort(int arr[], int n, int &comparisons) {
    comparisons = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap) {
                comparisons++;
                if (arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    j -= gap;
                } else {
                    break;
                }
            }
            arr[j] = temp;
        }
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

int main() {
    srand(time(0));
    
    int size = 20;
    int original[100];
    int arr[100];
    int comparisons;
    
    cout << "=== Testing with 20 random integers ===" << endl;
    cout << "\nGenerating random array (1-100):" << endl;
    for (int i = 0; i < size; i++) {
        original[i] = rand() % 100 + 1;
        cout << original[i] << " ";
    }
    cout << "\n" << endl;
    
    copyArray(original, arr, size);
    bubbleSort(arr, size, comparisons);
    cout << "Bubble Sort Result:" << endl;
    displayArray(arr, size);
    cout << "Comparisons: " << comparisons << "\n" << endl;
    
    copyArray(original, arr, size);
    insertionSort(arr, size, comparisons);
    cout << "Insertion Sort Result:" << endl;
    displayArray(arr, size);
    cout << "Comparisons: " << comparisons << "\n" << endl;
    
    copyArray(original, arr, size);
    selectionSort(arr, size, comparisons);
    cout << "Selection Sort Result:" << endl;
    displayArray(arr, size);
    cout << "Comparisons: " << comparisons << "\n" << endl;
    
    copyArray(original, arr, size);
    shellSort(arr, size, comparisons);
    cout << "Shell Sort Result:" << endl;
    displayArray(arr, size);
    cout << "Comparisons: " << comparisons << "\n" << endl;
    
    size = 100;
    cout << "\n=== Testing with 100 random integers ===" << endl;
    cout << "\nGenerating random array (1-100)..." << endl;
    for (int i = 0; i < size; i++) {
        original[i] = rand() % 100 + 1;
    }
    
    copyArray(original, arr, size);
    bubbleSort(arr, size, comparisons);
    cout << "\nBubble Sort - Comparisons: " << comparisons << endl;
    
    copyArray(original, arr, size);
    insertionSort(arr, size, comparisons);
    cout << "Insertion Sort - Comparisons: " << comparisons << endl;
    
    copyArray(original, arr, size);
    selectionSort(arr, size, comparisons);
    cout << "Selection Sort - Comparisons: " << comparisons << endl;
    
    copyArray(original, arr, size);
    shellSort(arr, size, comparisons);
    cout << "Shell Sort - Comparisons: " << comparisons << endl;
    
    return 0;
}