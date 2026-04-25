#include <iostream>
#include <string>
using namespace std;

struct Node {
    string contactName;
    Node* left;
    Node* right;
};

Node* makeNode(string name) {
    Node* n = new Node();
    n->contactName = name;
    n->left = n->right = nullptr;
    return n;
}

Node* insert(Node* root, string name) {
    if (!root) return makeNode(name);
    if (name < root->contactName)
        root->left = insert(root->left, name);
    else
        root->right = insert(root->right, name);
    return root;
}

bool searchContact(Node* root, string name) {
    if (!root) return false;
    if (root->contactName == name) return true;
    if (name < root->contactName)
        return searchContact(root->left, name);
    return searchContact(root->right, name);
}

int main() {
    Node* root = nullptr;
    root = insert(root, "Zain");
    root = insert(root, "Ahmed");
    root = insert(root, "Sara");
    root = insert(root, "Bilal");
    root = insert(root, "Omar");

    string query;
    cout << "enter contact name to search: ";
    cin >> query;

    if (searchContact(root, query))
        cout << query << " found in phonebook" << endl;
    else
        cout << query << " not found" << endl;

    return 0;
}
