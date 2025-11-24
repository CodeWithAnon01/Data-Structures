#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int* arr = new int[n];
    
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element " << (i + 1) << ": ";
        cin >> arr[i];
    }
    
    cout << "\nOriginal Array:" << endl;
    displayArray(arr, n);
    
    bubbleSort(arr, n);
    
    cout << "\nSorted Array (Ascending Order):" << endl;
    displayArray(arr, n);
    
    int target;
    cout << "\nEnter the value to search: ";
    cin >> target;
    
    int result = binarySearch(arr, n, target);
    
    if (result != -1) {
        cout << "\nElement " << target << " found at index " << result << endl;
        cout << "Position in sorted array: " << (result + 1) << endl;
    } else {
        cout << "\nElement " << target << " not found in the array" << endl;
    }
    
    delete[] arr;
    
    return 0;
}