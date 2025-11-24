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
            cout << "Heap is full!" << endl;
            return;
        }
        
        heap[size] = value;
        heapifyUp(size);
        size++;
        cout << "Inserted " << value << endl;
    }
    
    int extractMin() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        
        int minValue = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        
        return minValue;
    }
    
    int getMin() {
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
        
        cout << "Min Heap: ";
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
    
    ~MinHeap() {
        delete[] heap;
    }
};

int main() {
    MinHeap minHeap(15);
    
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(5);
    minHeap.insert(30);
    minHeap.insert(15);
    minHeap.insert(25);
    minHeap.insert(3);
    
    minHeap.display();
    
    cout << "\nMinimum element: " << minHeap.getMin() << endl;
    
    cout << "\nExtracting minimum: " << minHeap.extractMin() << endl;
    minHeap.display();
    
    cout << "\nExtracting minimum: " << minHeap.extractMin() << endl;
    minHeap.display();
    
    return 0;
}