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

int interpolationSearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) {
                return low;
            }
            return -1;
        }
        
        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (target - arr[low]));
        
        if (arr[pos] == target) {
            return pos;
        }
        
        if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
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
    
    cout << "\nSorted Array:" << endl;
    displayArray(arr, n);
    
    int target;
    cout << "\nEnter the value to search: ";
    cin >> target;
    
    int result = interpolationSearch(arr, n, target);
    
    if (result != -1) {
        cout << "\nElement " << target << " found at index " << result << endl;
    } else {
        cout << "\nElement " << target << " not found in the array" << endl;
    }
    
    delete[] arr;
    
    return 0;
}