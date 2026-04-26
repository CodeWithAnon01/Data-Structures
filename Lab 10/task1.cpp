#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

struct ListNode {
    int val;
    ListNode* next;
};

Node* makeNode(int v) {
    Node* n = new Node();
    n->val = v; n->left = n->right = nullptr;
    return n;
}

ListNode* makeLNode(int v) {
    ListNode* n = new ListNode();
    n->val = v; n->next = nullptr;
    return n;
}

void inorderToList(Node* root, ListNode*& tail, ListNode*& head) {
    if (!root) return;
    inorderToList(root->left, tail, head);
    ListNode* nd = makeLNode(root->val);
    if (!head) { head = tail = nd; }
    else { tail->next = nd; tail = nd; }
    inorderToList(root->right, tail, head);
}

int getListLen(ListNode* h) {
    int cnt = 0;
    while (h) { cnt++; h = h->next; }
    return cnt;
}

Node* buildBalancedTree(ListNode*& curr, int n) {
    if (n <= 0) return nullptr;
    Node* left = buildBalancedTree(curr, n/2);
    Node* root = makeNode(curr->val);
    curr = curr->next;
    root->left = left;
    root->right = buildBalancedTree(curr, n - n/2 - 1);
    return root;
}

int getHeight(Node* root) {
    if (!root) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

int main() {
    Node* skewed = nullptr;
    int vals[] = {1, 2, 3, 4, 5, 6, 7};
    Node* curr2 = nullptr;
    for (int v : vals) {
        Node* nd = makeNode(v);
        if (!skewed) { skewed = nd; curr2 = nd; }
        else { curr2->right = nd; curr2 = nd; }
    }
    cout << "skewed tree height: " << getHeight(skewed) << endl;

    ListNode* lhead = nullptr;
    ListNode* ltail = nullptr;
    inorderToList(skewed, ltail, lhead);

    int len = getListLen(lhead);
    ListNode* lPtr = lhead;
    Node* balanced = buildBalancedTree(lPtr, len);

    cout << "balanced tree height: " << getHeight(balanced) << endl;
    cout << "height reduced from " << getHeight(skewed) << " to " << getHeight(balanced) << endl;

    return 0;
}
