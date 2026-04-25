#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

Node* makeNode(int v) {
    Node* n = new Node();
    n->val = v;
    n->left = n->right = nullptr;
    return n;
}

void postOrder(Node* root, int& totalSize) {
    if (!root) return;
    postOrder(root->left, totalSize);
    postOrder(root->right, totalSize);
    totalSize += root->val;
    cout << "visiting node with size " << root->val << " KB" << endl;
}

int calcTotalSize(Node* root) {
    if (!root) return 0;
    return calcTotalSize(root->left) + calcTotalSize(root->right) + root->val;
}

int main() {
    Node* root = makeNode(50);
    root->left = makeNode(30);
    root->right = makeNode(20);
    root->left->left = makeNode(10);
    root->left->right = makeNode(15);
    root->right->left = makeNode(5);

    cout << "post-order traversal (left->right->parent):" << endl;
    int total = 0;
    postOrder(root, total);
    cout << "\ntotal storage space: " << total << " KB" << endl;
    cout << "verified total: " << calcTotalSize(root) << " KB" << endl;

    return 0;
}
