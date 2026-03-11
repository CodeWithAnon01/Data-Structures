#include <iostream>
using namespace std;

int bubbleSortCount(int arr[], int n) {
    int swaps = 0;
    for (int i = 0; i < n-1; i++) {
        bool swpd = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swaps++;
                swpd = true;
            }
        }
        if (!swpd) break;
    }
    return swaps;
}

void combSort(int arr[], int n) {
    int gap = n;
    float shrink = 1.3;
    bool sorted = false;

    while (!sorted) {
        gap = (int)(gap / shrink);
        if (gap <= 1) { gap = 1; sorted = true; }

        cout << "gap this pass: " << gap << endl;

        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                sorted = false;
            }
        }
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "enter size of array: ";
    cin >> n;
    int* arr = new int[n];
    cout << "enter numbers: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int* arrCopy = new int[n];
    for (int i = 0; i < n; i++) arrCopy[i] = arr[i];

    cout << "\ncomb sort gap values:" << endl;
    combSort(arr, n);
    cout << "comb sorted: ";
    printArr(arr, n);

    cout << "\nbubble sort on reverse sorted {9,8,7,6,5,4,3,2,1}:" << endl;
    int rev[9] = {9,8,7,6,5,4,3,2,1};
    int revCopy[9] = {9,8,7,6,5,4,3,2,1};

    int bSwaps = bubbleSortCount(rev, 9);
    cout << "bubble sort swaps: " << bSwaps << endl;

    cout << "\ncomb sort on {9,8,7,6,5,4,3,2,1}:" << endl;
    combSort(revCopy, 9);
    cout << "comb sorted result: ";
    printArr(revCopy, 9);
    cout << "comb generally faster on reverse sorted due to bigger gap jumps" << endl;

    delete[] arr;
    delete[] arrCopy;
    return 0;
}
