#include <iostream>
using namespace std;

struct Node {
    int priority;
    Node* left;
    Node* right;
};

Node* makeNode(int v) {
    Node* n = new Node();
    n->priority = v;
    n->left = n->right = nullptr;
    return n;
}

Node* insert(Node* root, int v) {
    if (!root) return makeNode(v);
    if (v < root->priority)
        root->left = insert(root->left, v);
    else
        root->right = insert(root->right, v);
    return root;
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int v) {
    if (!root) return nullptr;
    if (v < root->priority)
        root->left = deleteNode(root->left, v);
    else if (v > root->priority)
        root->right = deleteNode(root->right, v);
    else {
        if (!root->left) {
            Node* tmp = root->right;
            delete root;
            return tmp;
        } else if (!root->right) {
            Node* tmp = root->left;
            delete root;
            return tmp;
        }
        Node* successor = findMin(root->right);
        root->priority = successor->priority;
        root->right = deleteNode(root->right, successor->priority);
    }
    return root;
}

void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->priority << " ";
    inOrder(root->right);
}

int main() {
    Node* root = nullptr;
    int tasks[] = {50, 30, 70, 20, 40, 60, 80};
    for (int t : tasks)
        root = insert(root, t);

    cout << "task queue (in order): ";
    inOrder(root);
    cout << endl;

    int doneTask;
    cout << "enter completed task priority to remove: ";
    cin >> doneTask;
    root = deleteNode(root, doneTask);

    cout << "after removing task " << doneTask << ": ";
    inOrder(root);
    cout << endl;

    return 0;
}
