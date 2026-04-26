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
void updateHt(Node* n) { if (n) n->ht = 1 + max(getHt(n->left), getHt(n->right)); }
int getBalance(Node* n) { return n ? getHt(n->left) - getHt(n->right) : 0; }

Node* rightRotate(Node* y) {
    Node* x = y->left; Node* T2 = x->right;
    x->right = y; y->left = T2;
    updateHt(y); updateHt(x);
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right; Node* T2 = y->left;
    y->left = x; x->right = T2;
    updateHt(x); updateHt(y);
    return y;
}

Node* insert(Node* root, int v) {
    if (!root) return makeNode(v);
    if (v < root->val) root->left = insert(root->left, v);
    else root->right = insert(root->right, v);
    updateHt(root);
    int bal = getBalance(root);
    if (bal > 1 && v < root->left->val) return rightRotate(root);
    if (bal < -1 && v > root->right->val) return leftRotate(root);
    if (bal > 1 && v > root->left->val) { root->left = leftRotate(root->left); return rightRotate(root); }
    if (bal < -1 && v < root->right->val) { root->right = rightRotate(root->right); return leftRotate(root); }
    return root;
}

Node* findMin(Node* n) { while (n->left) n = n->left; return n; }

Node* deleteNode(Node* root, int v) {
    if (!root) return nullptr;
    if (v < root->val) root->left = deleteNode(root->left, v);
    else if (v > root->val) root->right = deleteNode(root->right, v);
    else {
        if (!root->left || !root->right) {
            Node* tmp = root->left ? root->left : root->right;
            delete root;
            return tmp;
        }
        Node* succ = findMin(root->right);
        root->val = succ->val;
        root->right = deleteNode(root->right, succ->val);
    }

    updateHt(root);
    int bal = getBalance(root);

    if (bal > 1 && getBalance(root->left) >= 0) {
        cout << "LL case after delete" << endl;
        return rightRotate(root);
    }
    if (bal > 1 && getBalance(root->left) < 0) {
        cout << "LR case after delete" << endl;
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (bal < -1 && getBalance(root->right) <= 0) {
        cout << "RR case after delete" << endl;
        return leftRotate(root);
    }
    if (bal < -1 && getBalance(root->right) > 0) {
        cout << "RL case after delete" << endl;
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->val << "(h=" << root->ht << ",b=" << getBalance(root) << ") ";
    inOrder(root->right);
}

int main() {
    Node* root = nullptr;
    int vals[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : vals)
        root = insert(root, v);

    cout << "tree before deletions (inorder with height and balance):" << endl;
    inOrder(root);
    cout << endl;

    cout << "\ndeleting 30:" << endl;
    root = deleteNode(root, 30);
    cout << "deleting 70:" << endl;
    root = deleteNode(root, 70);

    cout << "\ntree after deletions:" << endl;
    inOrder(root);
    cout << endl;

    return 0;
}
