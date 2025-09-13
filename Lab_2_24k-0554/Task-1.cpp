#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int size;
    int capacity;

public:
    DynamicArray() {
        capacity = 2;
        size = 0;
        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void push_back(int element) {
        if (size >= capacity) {
            resize();
        }
        data[size] = element;
        size++;
    }

    void printArray() {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
        cout << "Size: " << size << ", Capacity: " << capacity << endl;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

private:
    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        
        delete[] data;
        data = newData;
    }
};

int main() {
    DynamicArray arr;
    
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);
    
    arr.printArray();
    
    cout << "Element at index 2: " << arr[2] << endl;
    
    return 0;
}