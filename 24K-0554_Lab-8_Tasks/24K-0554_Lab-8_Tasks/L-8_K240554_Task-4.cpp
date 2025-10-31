#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) { data = val; left = right = nullptr; }
};

int subtreeSum(Node* root, int target, bool &found) {
    if (!root) return 0;
    int sum = root->data + subtreeSum(root->left, target, found) + subtreeSum(root->right, target, found);
    if (sum == target) found = true;
    return sum;
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);

    int target = 9;
    bool found = false;
    subtreeSum(root, target, found);

    if (found)
        cout << "Subtree with sum " << target << " exists." << endl;
    else
        cout << "No subtree found with sum " << target << "." << endl;

    return 0;
}
