#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string bookTitle;
    Node* next;
    
    Node(string title) {
        bookTitle = title;
        next = nullptr;
    }
};

class LibraryList {
private:
    Node* head;

public:
    LibraryList() {
        head = nullptr;
        head = new Node("Data Structures");
        head->next = new Node("Operating Systems");
        head->next->next = new Node("Computer Networks");
        head->next->next->next = new Node("Database Systems");
    }

    ~LibraryList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addToFront(string title) {
        Node* newNode = new Node(title);
        newNode->next = head;
        head = newNode;
    }

    void addToEnd(string title) {
        Node* newNode = new Node(title);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void insertAfter(string afterTitle, string newTitle) {
        Node* current = head;
        while (current != nullptr && current->bookTitle != afterTitle) {
            current = current->next;
        }
        if (current != nullptr) {
            Node* newNode = new Node(newTitle);
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    bool searchBook(string title) {
        Node* current = head;
        while (current != nullptr) {
            if (current->bookTitle == title) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void displayBooks() {
        cout << "Library Books:" << endl;
        Node* current = head;
        while (current != nullptr) {
            cout << "- " << current->bookTitle << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LibraryList library;
    
    cout << "Initial library:" << endl;
    library.displayBooks();
    
    library.addToFront("Artificial Intelligence");
    cout << "After adding 'Artificial Intelligence' at front:" << endl;
    library.displayBooks();
    
    library.addToEnd("Machine Learning");
    cout << "After adding 'Machine Learning' at end:" << endl;
    library.displayBooks();
    
    library.insertAfter("Operating Systems", "Cyber Security");
    cout << "After inserting 'Cyber Security' after 'Operating Systems':" << endl;
    library.displayBooks();
    
    if (library.searchBook("Database Systems")) {
        cout << "'Database Systems' exists in the list." << endl;
    } else {
        cout << "'Database Systems' does not exist in the list." << endl;
    }
    
    return 0;
}