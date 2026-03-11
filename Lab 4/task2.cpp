#include <iostream>
#include <string>
using namespace std;

void selectionSortNames(string cities[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (cities[j] < cities[minIdx])
                minIdx = j;
        }
        if (minIdx != i)
            swap(cities[i], cities[minIdx]);
    }
}

int selectionSortCount(int arr[], int n) {
    int swapCnt = 0;
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
            swapCnt++;
        }
    }
    return swapCnt;
}

int main() {
    string cities[5] = {"Karachi", "Lahore", "Islamabad", "Peshawar", "Quetta"};
    cout << "cities before sort: ";
    for (auto c : cities) cout << c << " ";
    cout << endl;

    selectionSortNames(cities, 5);
    cout << "cities after sort: ";
    for (auto c : cities) cout << c << " ";
    cout << endl;

    int nums[5] = {29, 10, 14, 37, 13};
    int swaps = selectionSortCount(nums, 5);
    cout << "\nswaps for {29,10,14,37,13}: " << swaps << endl;
    cout << "sorted: ";
    for (int i = 0; i < 5; i++) cout << nums[i] << " ";
    cout << endl;

    return 0;
}
