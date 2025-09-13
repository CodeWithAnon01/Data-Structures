#include <iostream>
#include <string>
using namespace std;

class BookNode {
public:
    string title;
    int position;
    BookNode* next;
    
    BookNode(string bookTitle, int pos = 0) {
        title = bookTitle;
        position = pos;
        next = nullptr;
    }
};

class CatalogList {
private:
    BookNode* head;
    int totalBooks;

    void updatePositions() {
        BookNode* current = head;
        int pos = 1;
        while (current != nullptr) {
            current->position = pos++;
            current = current->next;
        }
        totalBooks = pos - 1;
    }

public:
    CatalogList() {
        head = nullptr;
        totalBooks = 0;
    }

    ~CatalogList() {
        while (head != nullptr) {
            BookNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addBookToTail(string title) {
        BookNode* newBook = new BookNode(title);
        if (head == nullptr) {
            head = newBook;
        } else {
            BookNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newBook;
        }
        updatePositions();
        cout << "Added '" << title << "' to the catalog." << endl;
    }

    void deleteBookFromFront() {
        if (head == nullptr) {
            cout << "Catalog is empty. Cannot delete." << endl;
            return;
        }
        BookNode* temp = head;
        string deletedTitle = head->title;
        head = head->next;
        delete temp;
        updatePositions();
        cout << "Deleted '" << deletedTitle << "' from the front of catalog." << endl;
    }

    void searchByTitle(string title) {
        BookNode* current = head;
        while (current != nullptr) {
            if (current->title == title) {
                cout << "Found: '" << title << "' at position " << current->position << endl;
                return;
            }
            current = current->next;
        }
        cout << "Book '" << title << "' not found in catalog." << endl;
    }

    void searchByPosition(int pos) {
        if (pos < 1 || pos > totalBooks) {
            cout << "Invalid position. Catalog has " << totalBooks << " books." << endl;
            return;
        }
        BookNode* current = head;
        while (current != nullptr && current->position != pos) {
            current = current->next;
        }
        if (current != nullptr) {
            cout << "At position " << pos << ": '" << current->title << "'" << endl;
        }
    }

    void displayCatalog() {
        if (head == nullptr) {
            cout << "Catalog is empty." << endl;
            return;
        }
        cout << "Library Catalog:" << endl;
        BookNode* current = head;
        while (current != nullptr) {
            cout << current->position << ". " << current->title << endl;
            current = current->next;
        }
        cout << "Total books: " << totalBooks << endl << endl;
    }
};

int main() {
    CatalogList catalog;
    
    catalog.addBookToTail("Data Structures");
    catalog.addBookToTail("Algorithms");
    catalog.addBookToTail("Operating Systems");
    catalog.addBookToTail("Database Systems");
    catalog.displayCatalog();
    
    catalog.searchByTitle("Algorithms");
    catalog.searchByPosition(3);
    
    catalog.deleteBookFromFront();
    catalog.displayCatalog();
    
    catalog.addBookToTail("Machine Learning");
    catalog.displayCatalog();
    
    catalog.searchByTitle("Data Structures");
    catalog.searchByPosition(2);
    
    return 0;
}