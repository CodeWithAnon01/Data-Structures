#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    Book* next;
};

Book* head = nullptr;

void insertFront(int id, string titl, string auth) {
    Book* nb = new Book();
    nb->id = id;
    nb->title = titl;
    nb->author = auth;
    nb->next = head;
    head = nb;
}

void insertEnd(int id, string titl, string auth) {
    Book* nb = new Book();
    nb->id = id;
    nb->title = titl;
    nb->author = auth;
    nb->next = nullptr;
    if (!head) { head = nb; return; }
    Book* tmp = head;
    while (tmp->next) tmp = tmp->next;
    tmp->next = nb;
}

void insertAt(int pos, int id, string titl, string auth) {
    if (pos <= 0 || !head) {
        insertFront(id, titl, auth);
        return;
    }
    Book* nb = new Book();
    nb->id = id;
    nb->title = titl;
    nb->author = auth;
    Book* curr = head;
    for (int i = 0; i < pos-1 && curr->next; i++)
        curr = curr->next;
    nb->next = curr->next;
    curr->next = nb;
}

void deleteFront() {
    if (!head) { cout << "list empty" << endl; return; }
    Book* tmp = head;
    head = head->next;
    cout << "deleted book: " << tmp->title << endl;
    delete tmp;
}

void deleteEnd() {
    if (!head) { cout << "list empty" << endl; return; }
    if (!head->next) {
        cout << "deleted book: " << head->title << endl;
        delete head;
        head = nullptr;
        return;
    }
    Book* curr = head;
    while (curr->next->next) curr = curr->next;
    cout << "deleted book: " << curr->next->title << endl;
    delete curr->next;
    curr->next = nullptr;
}

void deleteAt(int pos) {
    if (!head) { cout << "list empty" << endl; return; }
    if (pos == 0) { deleteFront(); return; }
    Book* curr = head;
    for (int i = 0; i < pos-1 && curr->next; i++)
        curr = curr->next;
    if (!curr->next) { cout << "pos out of range" << endl; return; }
    Book* tmp = curr->next;
    curr->next = tmp->next;
    cout << "deleted at pos " << pos << ": " << tmp->title << endl;
    delete tmp;
}

void searchByID(int sid) {
    Book* tmp = head;
    while (tmp) {
        if (tmp->id == sid) {
            cout << "found -> ID: " << tmp->id << " | " << tmp->title << " by " << tmp->author << endl;
            return;
        }
        tmp = tmp->next;
    }
    cout << "book with id " << sid << " not found" << endl;
}

void showBooks() {
    Book* tmp = head;
    cout << "book list:" << endl;
    while (tmp) {
        cout << "ID: " << tmp->id << " | " << tmp->title << " by " << tmp->author << endl;
        tmp = tmp->next;
    }
}

int main() {
    insertEnd(1, "Data Structs", "Mark Allen");
    insertEnd(2, "Algo Design", "Kleinberg");
    insertFront(0, "C++ Primer", "Lippman");
    insertAt(2, 99, "OS Concepts", "Silberschatz");

    showBooks();

    deleteFront();
    deleteEnd();
    deleteAt(1);

    cout << "\nafter deletions:" << endl;
    showBooks();

    searchByID(99);
    searchByID(55);

    return 0;
}
