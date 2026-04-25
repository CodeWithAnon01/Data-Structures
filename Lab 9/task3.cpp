#include <iostream>
#include <string>
using namespace std;

struct Node {
    string word;
    Node* left;
    Node* right;
};

Node* makeNode(string w) {
    Node* n = new Node();
    n->word = w;
    n->left = n->right = nullptr;
    return n;
}

Node* insertWord(Node* root, string w) {
    if (!root) return makeNode(w);
    if (w <= root->word)
        root->left = insertWord(root->left, w);
    else
        root->right = insertWord(root->right, w);
    return root;
}

void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->word << " ";
    inOrder(root->right);
}

int main() {
    Node* root = nullptr;
    string words[] = {"apple", "mango", "banana", "grape", "cherry", "fig"};

    for (auto w : words)
        root = insertWord(root, w);

    cout << "dictionary words in order (auto-complete would use this):" << endl;
    inOrder(root);
    cout << endl;

    string newWord;
    cout << "enter a new word to add: ";
    cin >> newWord;
    root = insertWord(root, newWord);

    cout << "after adding '" << newWord << "':" << endl;
    inOrder(root);
    cout << endl;

    return 0;
}
