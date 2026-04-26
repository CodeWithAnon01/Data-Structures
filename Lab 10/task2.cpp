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
    x->right = y;
    y->left = T2;
    updateHt(y);
    updateHt(x);
    cout << "right rotation on " << y->val << endl;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    updateHt(x);
    updateHt(y);
    cout << "left rotation on " << x->val << endl;
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

    if (bal < -1 && v > root->right->val) {
        cout << "RR case detected" << endl;
        return leftRotate(root);
    }
    if (bal > 1 && v < root->left->val) {
        cout << "LL case detected" << endl;
        return rightRotate(root);
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
    cout << "test 1 - RR case: inserting 30, 35, 45" << endl;
    Node* root1 = nullptr;
    for (int v : {30, 35, 45})
        root1 = insert(root1, v);
    cout << "result inorder: ";
    inOrder(root1);
    cout << endl;

    cout << "\ntest 2 - LL case: inserting 13, 10, 5" << endl;
    Node* root2 = nullptr;
    for (int v : {13, 10, 5})
        root2 = insert(root2, v);
    cout << "result inorder: ";
    inOrder(root2);
    cout << endl;

    return 0;
}
