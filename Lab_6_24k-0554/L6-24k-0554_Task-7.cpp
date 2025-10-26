#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Patron {
    string name;
    int bookCount;
    string transactionType;
};

class LibraryQueue {
    Patron* queue;
    int front;
    int rear;
    int capacity;
    int size;
    
public:
    LibraryQueue(int cap) {
        capacity = cap;
        queue = new Patron[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    void addPatron(string name, int books, string type) {
        if(isFull()) {
            cout << "Queue is full! " << name << " cannot join.\n";
            return;
        }
        
        rear = (rear + 1) % capacity;
        queue[rear].name = name;
        queue[rear].bookCount = books;
        queue[rear].transactionType = type;
        size++;
        
        cout << name << " joined queue for " << type << " " << books << " book(s)\n";
    }
    
    void servicePatron() {
        if(isEmpty()) {
            cout << "No patrons in queue.\n";
            return;
        }
        
        Patron p = queue[front];
        cout << "\nServicing: " << p.name << endl;
        cout << "Transaction: " << p.transactionType << " " << p.bookCount << " book(s)\n";
        cout << "Processing";
        
        for(int i = 0; i < 3; i++) {
            cout << ".";
            cout.flush();
        }
        
        cout << " Done!\n";
        
        front = (front + 1) % capacity;
        size--;
    }
    
    void displayQueue() {
        if(isEmpty()) {
            cout << "\nNo patrons waiting.\n";
            return;
        }
        
        cout << "\nCurrent Queue (" << size << " patron(s)):\n";
        int idx = front;
        for(int i = 0; i < size; i++) {
            cout << i+1 << ". " << queue[idx].name << " - " 
                 << queue[idx].transactionType << " " 
                 << queue[idx].bookCount << " book(s)\n";
            idx = (idx + 1) % capacity;
        }
        cout << endl;
    }
    
    void removePatron(string name) {
        if(isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        
        int idx = front;
        bool found = false;
        
        for(int i = 0; i < size; i++) {
            if(queue[idx].name == name) {
                found = true;
                cout << name << " left the queue.\n";
                
                for(int j = i; j < size - 1; j++) {
                    int curr = (front + j) % capacity;
                    int next = (front + j + 1) % capacity;
                    queue[curr] = queue[next];
                }
                
                if(rear == 0) rear = capacity - 1;
                else rear--;
                size--;
                break;
            }
            idx = (idx + 1) % capacity;
        }
        
        if(!found) {
            cout << name << " not found in queue.\n";
        }
    }
    
    ~LibraryQueue() {
        delete[] queue;
    }
};

int main() {
    LibraryQueue library(10);
    
    library.addPatron("Alice", 2, "borrow");
    library.addPatron("Bob", 1, "return");
    library.addPatron("Charlie", 3, "borrow");
    library.addPatron("Diana", 2, "return");
    
    library.displayQueue();
    
    library.servicePatron();
    library.displayQueue();
    
    library.servicePatron();
    library.displayQueue();
    
    library.addPatron("Eve", 1, "borrow");
    library.displayQueue();
    
    library.removePatron("Charlie");
    library.displayQueue();
    
    library.servicePatron();
    library.servicePatron();
    library.displayQueue();
    
    return 0;
}