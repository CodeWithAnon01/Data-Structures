#include <iostream>
#include <string>
using namespace std;

struct Node {
    string word;
    Node* next;
    
    Node(string w) : word(w), next(nullptr) {}
};

class Dictionary {
private:
    Node** table;
    int tableSize;
    
    int hashFunction(string word) {
        int sum = 0;
        for (char c : word) {
            sum += int(c);
        }
        return sum % tableSize;
    }
    
public:
    Dictionary() {
        tableSize = 100;
        table = new Node*[tableSize];
        for (int i = 0; i < tableSize; i++) {
            table[i] = nullptr;
        }
    }
    
    void Add_Record(string word) {
        int index = hashFunction(word);
        Node* newNode = new Node(word);
        
        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Word '" << word << "' added successfully." << endl;
    }
    
    void Word_Search(string word) {
        int index = hashFunction(word);
        Node* temp = table[index];
        
        while (temp != nullptr) {
            if (temp->word == word) {
                cout << "Word '" << word << "' found in dictionary." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Error: Word '" << word << "' not found in dictionary." << endl;
    }
    
    void Print_Dictionary() {
        cout << "\n--- Dictionary Contents ---" << endl;
        bool isEmpty = true;
        
        for (int i = 0; i < tableSize; i++) {
            if (table[i] != nullptr) {
                Node* temp = table[i];
                while (temp != nullptr) {
                    cout << temp->word << endl;
                    temp = temp->next;
                    isEmpty = false;
                }
            }
        }
        
        if (isEmpty) {
            cout << "Dictionary is empty." << endl;
        }
        cout << "----------------------------\n" << endl;
    }
    
    ~Dictionary() {
        for (int i = 0; i < tableSize; i++) {
            Node* temp = table[i];
            while (temp != nullptr) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
        delete[] table;
    }
};

int main() {
    Dictionary dict;
    int choice;
    string word;
    
    do {
        cout << "\n=== ASCII Dictionary Menu ===" << endl;
        cout << "1. Add Record" << endl;
        cout << "2. Search Word" << endl;
        cout << "3. Print Dictionary" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter word to add: ";
                cin >> word;
                dict.Add_Record(word);
                break;
            case 2:
                cout << "Enter word to search: ";
                cin >> word;
                dict.Word_Search(word);
                break;
            case 3:
                dict.Print_Dictionary();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 4);
    
    return 0;
}