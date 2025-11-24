#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* heap;
    int capacity;
    int size;
    
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }
    
    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }
    
    void heapifyDown(int index) {
        int maxIndex = index;
        int left = leftChild(index);
        int right = rightChild(index);
        
        if (left < size && heap[left] > heap[maxIndex]) {
            maxIndex = left;
        }
        
        if (right < size && heap[right] > heap[maxIndex]) {
            maxIndex = right;
        }
        
        if (index != maxIndex) {
            swap(heap[index], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }
    
public:
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[capacity];
    }
    
    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }
        
        heap[size] = value;
        heapifyUp(size);
        size++;
        cout << "Inserted " << value << endl;
    }
    
    int extractMax() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        
        int maxValue = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        
        return maxValue;
    }
    
    int getMax() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return heap[0];
    }
    
    void display() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }
        
        cout << "Max Heap: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    int getSize() {
        return size;
    }
    
    ~MaxHeap() {
        delete[] heap;
    }
};

int main() {
    MaxHeap maxHeap(15);
    
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(30);
    maxHeap.insert(15);
    maxHeap.insert(25);
    
    maxHeap.display();
    
    cout << "\nMaximum element: " << maxHeap.getMax() << endl;
    
    cout << "\nExtracting maximum: " << maxHeap.extractMax() << endl;
    maxHeap.display();
    
    cout << "\nExtracting maximum: " << maxHeap.extractMax() << endl;
    maxHeap.display();
    
    return 0;
}