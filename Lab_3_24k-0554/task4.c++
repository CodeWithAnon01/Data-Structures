#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedListUtils {
private:
    Node* head;

public:
    LinkedListUtils() {
        head = nullptr;
    }

    ~LinkedListUtils() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr || head->data >= value) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->data < value) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void sortList() {
        if (head == nullptr || head->next == nullptr) return;
        
        bool swapped;
        do {
            swapped = false;
            Node* current = head;
            Node* prev = nullptr;
            
            while (current->next != nullptr) {
                if (current->data > current->next->data) {
                    if (prev == nullptr) {
                        head = current->next;
                        current->next = head->next;
                        head->next = current;
                        prev = head;
                    } else {
                        prev->next = current->next;
                        current->next = current->next->next;
                        prev->next->next = current;
                        prev = prev->next;
                    }
                    swapped = true;
                } else {
                    prev = current;
                    current = current->next;
                }
            }
        } while (swapped);
    }

    LinkedListUtils* concatenate(LinkedListUtils* other) {
        LinkedListUtils* result = new LinkedListUtils();
        
        Node* current = head;
        while (current != nullptr) {
            result->insertAtEnd(current->data);
            current = current->next;
        }
        
        current = other->head;
        while (current != nullptr) {
            result->insertAtEnd(current->data);
            current = current->next;
        }
        
        return result;
    }

    int findMiddleElement() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return -1;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow->data;
    }

    void removeDuplicates() {
        if (head == nullptr) return;
        
        Node* current = head;
        while (current->next != nullptr) {
            if (current->data == current->next->data) {
                Node* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate;
            } else {
                current = current->next;
            }
        }
    }

    LinkedListUtils* mergeSortedLists(LinkedListUtils* other) {
        LinkedListUtils* result = new LinkedListUtils();
        Node* ptr1 = head;
        Node* ptr2 = other->head;
        
        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1->data <= ptr2->data) {
                result->insertAtEnd(ptr1->data);
                ptr1 = ptr1->next;
            } else {
                result->insertAtEnd(ptr2->data);
                ptr2 = ptr2->next;
            }
        }
        
        while (ptr1 != nullptr) {
            result->insertAtEnd(ptr1->data);
            ptr1 = ptr1->next;
        }
        
        while (ptr2 != nullptr) {
            result->insertAtEnd(ptr2->data);
            ptr2 = ptr2->next;
        }
        
        return result;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
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

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void createTestList(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            insertAtEnd(arr[i]);
        }
    }
};

int main() {
    LinkedListUtils list1, list2;
    
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {5, 15, 25, 35, 45};
    
    list1.createTestList(arr1, 7);
    list2.createTestList(arr2, 5);
    
    cout << "Original list1: ";
    list1.display();
    
    list1.sortList();
    cout << "Sorted list1: ";
    list1.display();
    
    cout << "List2: ";
    list2.display();
    
    LinkedListUtils* concatenated = list1.concatenate(&list2);
    cout << "Concatenated list: ";
    concatenated->display();
    
    cout << "Middle element of list1: " << list1.findMiddleElement() << endl;
    
    LinkedListUtils list3;
    int arr3[] = {1, 2, 2, 3, 3, 3, 4, 5, 5};
    list3.createTestList(arr3, 9);
    cout << "List with duplicates: ";
    list3.display();
    
    list3.removeDuplicates();
    cout << "After removing duplicates: ";
    list3.display();
    
    LinkedListUtils sortedList1, sortedList2;
    int sorted1[] = {1, 3, 5, 7};
    int sorted2[] = {2, 4, 6, 8, 10};
    
    sortedList1.createTestList(sorted1, 4);
    sortedList2.createTestList(sorted2, 5);
    
    cout << "Sorted list 1: ";
    sortedList1.display();
    cout << "Sorted list 2: ";
    sortedList2.display();
    
    LinkedListUtils* merged = sortedList1.mergeSortedLists(&sortedList2);
    cout << "Merged sorted list: ";
    merged->display();
    
    delete concatenated;
    delete merged;
    
    return 0;
}