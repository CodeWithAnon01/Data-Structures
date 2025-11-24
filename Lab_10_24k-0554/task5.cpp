#include <iostream>
using namespace std;

class MinHeap {
private:
    int* heap;
    int capacity;
    int size;
    
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }
    
    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] > heap[index]) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }
    
    void heapifyDown(int index) {
        int minIndex = index;
        int left = leftChild(index);
        int right = rightChild(index);
        
        if (left < size && heap[left] < heap[minIndex]) {
            minIndex = left;
        }
        
        if (right < size && heap[right] < heap[minIndex]) {
            minIndex = right;
        }
        
        if (index != minIndex) {
            swap(heap[index], heap[minIndex]);
            heapifyDown(minIndex);
        }
    }
    
public:
    MinHeap(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[capacity];
    }
    
    void insert(int value) {
        if (size == capacity) {
            if (value > heap[0]) {
                heap[0] = value;
                heapifyDown(0);
            }
        } else {
            heap[size] = value;
            heapifyUp(size);
            size++;
        }
    }
    
    int getMin() {
        if (size == 0) {
            return -1;
        }
        return heap[0];
    }
    
    int getSize() {
        return size;
    }
    
    void display() {
        cout << "Min Heap: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
    
    ~MinHeap() {
        delete[] heap;
    }
};

int findKthLargest(int arr[], int n, int k) {
    MinHeap minHeap(k);
    
    for (int i = 0; i < n; i++) {
        minHeap.insert(arr[i]);
    }
    
    return minHeap.getMin();
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, k;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int* arr = new int[n];
    
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element " << (i + 1) << ": ";
        cin >> arr[i];
    }
    
    cout << "\nArray: ";
    displayArray(arr, n);
    
    cout << "\nEnter the value of k (to find kth largest): ";
    cin >> k;
    
    if (k < 1 || k > n) {
        cout << "Invalid value of k!" << endl;
    } else {
        int kthLargest = findKthLargest(arr, n, k);
        cout << "\nThe " << k << "th largest element is: " << kthLargest << endl;
    }
    
    delete[] arr;
    
    return 0;
}