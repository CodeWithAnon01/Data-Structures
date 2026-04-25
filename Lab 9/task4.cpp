#include <iostream>
#include <queue>
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

Node* makeFull(int v, Node* l, Node* r) {
    Node* n = makeNode(v);
    n->left = l;
    n->right = r;
    return n;
}

void preOrder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void printLevelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    cout << "level order (decision tree path):" << endl;
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << "node " << curr->val << endl;
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main() {
    Node* leaf1 = makeNode(1);
    Node* leaf2 = makeNode(2);
    Node* leaf3 = makeNode(3);
    Node* leaf4 = makeNode(4);

    Node* mid1 = makeFull(5, leaf1, leaf2);
    Node* mid2 = makeFull(6, leaf3, leaf4);
    Node* root = makeFull(7, mid1, mid2);

    cout << "pre-order traversal (doctor question sequence):" << endl;
    preOrder(root);
    cout << endl;

    printLevelOrder(root);

    return 0;
}
