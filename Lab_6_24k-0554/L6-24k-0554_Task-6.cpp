#include <iostream>
#include <string>
using namespace std;

struct Order {
    int orderID;
    string itemName;
    int quantity;
};

class RestaurantQueue {
    Order* queue;
    int front;
    int rear;
    int capacity;
    int size;
    
public:
    RestaurantQueue(int cap) {
        capacity = cap;
        queue = new Order[capacity];
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
    
    void enqueue(int id, string item, int qty) {
        if(isFull()) {
            cout << "Queue overflow! Cannot add order.\n";
            return;
        }
        
        rear = (rear + 1) % capacity;
        queue[rear].orderID = id;
        queue[rear].itemName = item;
        queue[rear].quantity = qty;
        size++;
        
        cout << "Order #" << id << " added: " << item << " x" << qty << endl;
    }
    
    void dequeue() {
        if(isEmpty()) {
            cout << "Queue underflow! No orders to process.\n";
            return;
        }
        
        cout << "Processing Order #" << queue[front].orderID << ": " 
             << queue[front].itemName << " x" << queue[front].quantity << endl;
        
        front = (front + 1) % capacity;
        size--;
    }
    
    void displayOrders() {
        if(isEmpty()) {
            cout << "No pending orders.\n";
            return;
        }
        
        cout << "\nPending Orders:\n";
        int idx = front;
        for(int i = 0; i < size; i++) {
            cout << "Order #" << queue[idx].orderID << ": " 
                 << queue[idx].itemName << " x" << queue[idx].quantity << endl;
            idx = (idx + 1) % capacity;
        }
        cout << endl;
    }
    
    ~RestaurantQueue() {
        delete[] queue;
    }
};

int main() {
    RestaurantQueue rq(5);
    
    rq.enqueue(1, "Pizza", 2);
    rq.enqueue(2, "Burger", 3);
    rq.enqueue(3, "Pasta", 1);
    
    rq.displayOrders();
    
    rq.dequeue();
    rq.dequeue();
    
    rq.displayOrders();
    
    rq.enqueue(4, "Salad", 2);
    rq.enqueue(5, "Steak", 1);
    
    rq.displayOrders();
    
    return 0;
}