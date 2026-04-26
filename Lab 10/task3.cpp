#include <iostream>
using namespace std;

struct Node {
    int val, ht;
    Node* left;
    Node* right;
};

Node* makeNode(int v) {
    Node* n = new Node();
    n->val = v; n->ht = 1;
    n->left = n->right = nullptr;
    return n;
}

int getHt(Node* n) { return n ? n->ht : 0; }

void updateHt(Node* n) {
    if (n) n->ht = 1 + max(getHt(n->left), getHt(n->right));
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y; y->left = T2;
    updateHt(y); updateHt(x);
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x; x->right = T2;
    updateHt(x); updateHt(y);
    return y;
}

int getBalFactor(Node* n) {
    return n ? getHt(n->left) - getHt(n->right) : 0;
}

Node* insert(Node* root, int v) {
    if (!root) return makeNode(v);
    if (v < root->val) root->left = insert(root->left, v);
    else root->right = insert(root->right, v);

    updateHt(root);
    int bal = getBalFactor(root);

    if (bal > 1 && v < root->left->val)
        return rightRotate(root);

    if (bal < -1 && v > root->right->val)
        return leftRotate(root);

    if (bal > 1 && v > root->left->val) {
        cout << "LR case: rotating left on child first" << endl;
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bal < -1 && v < root->right->val) {
        cout << "RL case: rotating right on child first" << endl;
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main() {
    cout << "inserting {13, 10, 11} - LR case:" << endl;
    Node* root = nullptr;
    for (int v : {13, 10, 11})
        root = insert(root, v);

    cout << "root after balancing: " << root->val << " (should be 11)" << endl;
    cout << "inorder: ";
    inOrder(root);
    cout << endl;

    return 0;
}
