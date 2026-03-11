#include <iostream>
using namespace std;

int interpolSearch(int arr[], int n, int target, int& comps) {
    int lo = 0, hi = n - 1;
    comps = 0;
    while (lo <= hi && target >= arr[lo] && target <= arr[hi]) {
        comps++;
        if (lo == hi) {
            if (arr[lo] == target) return lo;
            return -1;
        }
        int pos = lo + ((double)(hi - lo) / (arr[hi] - arr[lo])) * (target - arr[lo]);
        if (arr[pos] == target) return pos;
        if (arr[pos] < target) lo = pos + 1;
        else hi = pos - 1;
    }
    return -1;
}

int binarySearch(int arr[], int n, int target, int& comps) {
    int lo = 0, hi = n - 1;
    comps = 0;
    while (lo <= hi) {
        comps++;
        int mid = (lo + hi) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int main() {
    int prices[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int n1 = 8;

    int p;
    cout << "enter price to search: ";
    cin >> p;

    int comps = 0;
    int res = interpolSearch(prices, n1, p, comps);
    if (res != -1)
        cout << "Price found at position " << res << endl;
    else
        cout << "Price not available" << endl;
    cout << "interpolation comparisons: " << comps << endl;

    int list2[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int n2 = 10;
    int searchVal = 45;

    int bComps = 0, iComps = 0;
    binarySearch(list2, n2, searchVal, bComps);
    interpolSearch(list2, n2, searchVal, iComps);

    cout << "\nsearching for 45 in {5,10,...,50}:" << endl;
    cout << "binary search comparisons: " << bComps << endl;
    cout << "interpolation search comparisons: " << iComps << endl;
    cout << "interpolation is more efficient here since values are evenly distributed" << endl;

    return 0;
}
