#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    
    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    
    Node* findLastNode(Node* start) {
        while (start != nullptr && start->next != nullptr)
            start = start->next;
        return start;
    }
    
    Node* divideList(Node* start, Node* end, Node** newStart, Node** newEnd) {
        Node* pivot = end;
        Node* previous = nullptr;
        Node* current = start;
        Node* lastNode = pivot;
        
        while (current != pivot) {
            if (current->value < pivot->value) {
                if (*newStart == nullptr)
                    *newStart = current;
                previous = current;
                current = current->next;
            } else {
                if (previous)
                    previous->next = current->next;
                Node* temp = current->next;
                current->next = nullptr;
                lastNode->next = current;
                lastNode = current;
                current = temp;
            }
        }
        
        if (*newStart == nullptr)
            *newStart = pivot;
        
        *newEnd = lastNode;
        
        return pivot;
    }
    
    Node* sortRecursively(Node* start, Node* end) {
        if (!start || start == end)
            return start;
        
        Node* newStart = nullptr;
        Node* newEnd = nullptr;
        
        Node* pivot = divideList(start, end, &newStart, &newEnd);
        
        if (newStart != pivot) {
            Node* temp = newStart;
            while (temp->next != pivot)
                temp = temp->next;
            temp->next = nullptr;
            
            newStart = sortRecursively(newStart, temp);
            
            temp = findLastNode(newStart);
            temp->next = pivot;
        }
        
        pivot->next = sortRecursively(pivot->next, newEnd);
        
        return newStart;
    }
    
public:
    LinkedList() : head(nullptr) {}
    
    void insertNumber(int number) {
        Node* newNode = new Node(number);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    
    void applyQuickSort() {
        head = sortRecursively(head, findLastNode(head));
    }
    
    void displayList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList numbers;
    int testData[] = {10, 7, 8, 9, 1, 5, 3};
    int dataSize = 7;
    
    cout << "Creating linked list with values: ";
    for (int i = 0; i < dataSize; i++) {
        cout << testData[i] << " ";
        numbers.insertNumber(testData[i]);
    }
    cout << endl;
    
    cout << "\nApplying Quick Sort...\n";
    numbers.applyQuickSort();
    
    cout << "\nSorted linked list: ";
    numbers.displayList();
    
    return 0;
}