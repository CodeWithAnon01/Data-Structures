#include <iostream>
using namespace std;

class CompartmentNode {
public:
    int compartmentNumber;
    CompartmentNode* next;
    CompartmentNode* prev;
    
    CompartmentNode(int num) {
        compartmentNumber = num;
        next = nullptr;
        prev = nullptr;
    }
};

class RailwayTrain {
private:
    CompartmentNode* head;
    CompartmentNode* tail;

public:
    RailwayTrain() {
        head = nullptr;
        tail = nullptr;
    }

    ~RailwayTrain() {
        while (head != nullptr) {
            CompartmentNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addCompartmentAtEnd(int compartmentNum) {
        CompartmentNode* newCompartment = new CompartmentNode(compartmentNum);
        
        if (head == nullptr) {
            head = tail = newCompartment;
        } else {
            tail->next = newCompartment;
            newCompartment->prev = tail;
            tail = newCompartment;
        }
        cout << "Added compartment " << compartmentNum << " at the end of train." << endl;
    }

    void removeFirstCompartment() {
        if (head == nullptr) {
            cout << "Train is empty. Cannot remove compartment." << endl;
            return;
        }
        
        CompartmentNode* temp = head;
        int removedNum = head->compartmentNumber;
        
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        
        delete temp;
        cout << "Removed compartment " << removedNum << " from the front of train." << endl;
    }

    void searchCompartment(int compartmentNum) {
        CompartmentNode* current = head;
        int position = 1;
        
        while (current != nullptr) {
            if (current->compartmentNumber == compartmentNum) {
                cout << "Compartment " << compartmentNum << " found at position " << position << endl;
                return;
            }
            current = current->next;
            position++;
        }
        cout << "Compartment " << compartmentNum << " not found in train." << endl;
    }

    void displayFrontToEnd() {
        if (head == nullptr) {
            cout << "Train is empty." << endl;
            return;
        }
        
        cout << "Train compartments (Front to End): ";
        CompartmentNode* current = head;
        while (current != nullptr) {
            cout << current->compartmentNumber;
            if (current->next != nullptr) cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }

    void displayEndToFront() {
        if (tail == nullptr) {
            cout << "Train is empty." << endl;
            return;
        }
        
        cout << "Train compartments (End to Front): ";
        CompartmentNode* current = tail;
        while (current != nullptr) {
            cout << current->compartmentNumber;
            if (current->prev != nullptr) cout << " -> ";
            current = current->prev;
        }
        cout << endl;
    }

    void displayCompartments() {
        displayFrontToEnd();
        displayEndToFront();
        cout << endl;
    }
};

int main() {
    RailwayTrain train;
    
    train.addCompartmentAtEnd(101);
    train.addCompartmentAtEnd(102);
    train.addCompartmentAtEnd(103);
    train.addCompartmentAtEnd(104);
    train.displayCompartments();
    
    train.searchCompartment(102);
    train.searchCompartment(105);
    
    train.removeFirstCompartment();
    train.displayCompartments();
    
    train.addCompartmentAtEnd(105);
    train.displayCompartments();
    
    return 0;
}