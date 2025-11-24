#include <iostream>
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

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0;
    
    cout << "Input list:" << endl;
    displayArray(arr, n);
    
    bubbleSort(arr, n, comparisons);
    
    cout << "\nSorted Element List:" << endl;
    displayArray(arr, n);
    
    cout << "\nTotal number of comparisons: " << comparisons << endl;
    
    return 0;
}