#include <iostream>
using namespace std;

struct Node {
    int val, ht;
    Node* left;
    Node* right;
};

struct QNode {
    Node* treeNode;
    QNode* next;
};

struct MyQueue {
    QNode* front;
    QNode* back;

    MyQueue() { front = back = nullptr; }

    void enq(Node* n) {
        QNode* qn = new QNode();
        qn->treeNode = n;
        qn->next = nullptr;
        if (!back) { front = back = qn; return; }
        back->next = qn;
        back = qn;
    }

    Node* deq() {
        if (!front) return nullptr;
        QNode* tmp = front;
        Node* res = tmp->treeNode;
        front = front->next;
        if (!front) back = nullptr;
        delete tmp;
        return res;
    }

    bool isEmpty() { return front == nullptr; }
};

Node* makeNode(int v) {
    Node* n = new Node();
    n->val = v; n->ht = 1;
    n->left = n->right = nullptr;
    return n;
}

int getHt(Node* n) { return n ? n->ht : 0; }
void updateHt(Node* n) { if (n) n->ht = 1 + max(getHt(n->left), getHt(n->right)); }

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

int getBalFactor(Node* n) { return n ? getHt(n->left) - getHt(n->right) : 0; }

Node* insert(Node* root, int v) {
    if (!root) return makeNode(v);
    if (v < root->val) root->left = insert(root->left, v);
    else root->right = insert(root->right, v);
    updateHt(root);
    int bal = getBalFactor(root);
    if (bal > 1 && v < root->left->val) return rightRotate(root);
    if (bal < -1 && v > root->right->val) return leftRotate(root);
    if (bal > 1 && v > root->left->val) { root->left = leftRotate(root->left); return rightRotate(root); }
    if (bal < -1 && v < root->right->val) { root->right = rightRotate(root->right); return leftRotate(root); }
    return root;
}

void printLevelOrder(Node* root) {
    if (!root) return;
    MyQueue q;
    q.enq(root);
    cout << "level order: ";
    while (!q.isEmpty()) {
        Node* curr = q.deq();
        cout << curr->val << "(bal=" << getBalFactor(curr) << ") ";
        if (curr->left) q.enq(curr->left);
        if (curr->right) q.enq(curr->right);
    }
    cout << endl;
}

Node* findMin(Node* root) { while (root->left) root = root->left; return root; }

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
    int bal = getBalFactor(root);
    if (bal > 1 && getBalFactor(root->left) >= 0) return rightRotate(root);
    if (bal > 1 && getBalFactor(root->left) < 0) { root->left = leftRotate(root->left); return rightRotate(root); }
    if (bal < -1 && getBalFactor(root->right) <= 0) return leftRotate(root);
    if (bal < -1 && getBalFactor(root->right) > 0) { root->right = rightRotate(root->right); return leftRotate(root); }
    return root;
}

int main() {
    Node* root = nullptr;
    int insertVals[] = {10, 20, 30, 40, 50};
    for (int v : insertVals)
        root = insert(root, v);
    cout << "after 5 insertions:" << endl;
    printLevelOrder(root);

    root = deleteNode(root, 20);
    root = deleteNode(root, 30);
    cout << "after deleting 20 and 30:" << endl;
    printLevelOrder(root);
    cout << "all balance factors shown - should be in range (-1, 0, 1)" << endl;

    return 0;
}
