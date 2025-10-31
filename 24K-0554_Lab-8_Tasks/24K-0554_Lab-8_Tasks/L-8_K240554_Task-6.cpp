#include <iostream>
using namespace std;

struct Node {
    int empID;
    Node* left;
    Node* right;
    Node(int id) { empID = id; left = right = nullptr; }
};

Node* insert(Node* root, int id) {
    if (!root) return new Node(id);
    if (id < root->empID) root->left = insert(root->left, id);
    else root->right = insert(root->right, id);
    return root;
}

Node* findLCA(Node* root, int n1, int n2) {
    if (!root) return nullptr;
    if (root->empID > n1 && root->empID > n2)
        return findLCA(root->left, n1, n2);
    if (root->empID < n1 && root->empID < n2)
        return findLCA(root->right, n1, n2);
    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);

    int emp1 = 5, emp2 = 15;
    Node* lca = findLCA(root, emp1, emp2);
    cout << "Lowest Common Manager of " << emp1 << " and " << emp2 << " is: " << lca->empID << endl;

    return 0;
}
