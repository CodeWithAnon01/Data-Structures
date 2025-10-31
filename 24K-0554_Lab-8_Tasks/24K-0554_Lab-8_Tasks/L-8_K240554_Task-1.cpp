#include <iostream>
#include <string>
using namespace std;

struct Node {
    string package;
    Node* left;
    Node* right;
    Node(string val) {
        package = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, string val) {
    if (root == nullptr) return new Node(val);
    if (val < root->package) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->package << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, "Europe");
    root = insert(root, "Asia");
    root = insert(root, "America");
    root = insert(root, "Africa");

    cout << "Hierarchy of Tour Packages (Inorder Traversal): ";
    inorder(root);
    cout << endl;
    return 0;
}
