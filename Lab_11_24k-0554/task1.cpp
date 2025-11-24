#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;
    Node* next;
    
    Node(string k) : key(k), next(nullptr) {}
};

class HashTable {
private:
    Node** buckets;
    int numBuckets;
    
    int hashFunction(string key) {
        int sum = 0;
        for (char c : key) {
            sum += int(c);
        }
        return sum % numBuckets;
    }
    
public:
    HashTable(int size) {
        numBuckets = size;
        buckets = new Node*[numBuckets];
        for (int i = 0; i < numBuckets; i++) {
            buckets[i] = nullptr;
        }
    }
    
    void insert(string key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);
        
        if (buckets[index] == nullptr) {
            buckets[index] = newNode;
        } else {
            Node* temp = buckets[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    bool search(string key) {
        int index = hashFunction(key);
        Node* temp = buckets[index];
        
        while (temp != nullptr) {
            if (temp->key == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    
    void display() {
        for (int i = 0; i < numBuckets; i++) {
            cout << "Bucket " << i << ": ";
            Node* temp = buckets[i];
            if (temp == nullptr) {
                cout << "NULL";
            } else {
                while (temp != nullptr) {
                    cout << temp->key;
                    if (temp->next != nullptr) {
                        cout << " -> ";
                    }
                    temp = temp->next;
                }
                cout << " -> NULL";
            }
            cout << endl;
        }
    }
    
    ~HashTable() {
        for (int i = 0; i < numBuckets; i++) {
            Node* temp = buckets[i];
            while (temp != nullptr) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
        delete[] buckets;
    }
};

int main() {
    HashTable ht(10);
    
    ht.insert("mango");
    ht.insert("apple");
    ht.insert("peach");
    ht.insert("grapes");
    ht.insert("banana");
    
    ht.display();
    
    cout << "\nSearching 'apple': " << (ht.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Searching 'orange': " << (ht.search("orange") ? "Found" : "Not Found") << endl;
    
    return 0;
}