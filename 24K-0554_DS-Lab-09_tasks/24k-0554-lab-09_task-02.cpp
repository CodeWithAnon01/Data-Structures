#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int value;
    Node* lft;
    Node* rgt;
    int hgt;
    
    Node(int val) {
        value = val;
        lft = nullptr;
        rgt = nullptr;
        hgt = 1;
    }
};

class AVLtree {
public:
    Node* root;
    
    AVLtree() {
        root = nullptr;
    }
    
    int getheight(Node* n) {
        if (n == nullptr)
            return 0;
        return n->hgt;
    }
    
    int getbal(Node* n) {
        if (n == nullptr)
            return 0;
        return getheight(n->lft) - getheight(n->rgt);
    }
    
    Node* rightrot(Node* y) {
        Node* x = y->lft;
        Node* T2 = x->rgt;
        
        x->rgt = y;
        y->lft = T2;
        
        y->hgt = max(getheight(y->lft), getheight(y->rgt)) + 1;
        x->hgt = max(getheight(x->lft), getheight(x->rgt)) + 1;
        
        return x;
    }
    
    Node* leftrot(Node* x) {
        Node* y = x->rgt;
        Node* T2 = y->lft;
        
        y->lft = x;
        x->rgt = T2;
        
        x->hgt = max(getheight(x->lft), getheight(x->rgt)) + 1;
        y->hgt = max(getheight(y->lft), getheight(y->rgt)) + 1;
        
        return y;
    }
    
    Node* insertnode(Node* node, int val) {
        if (node == nullptr)
            return new Node(val);
        
        if (val < node->value)
            node->lft = insertnode(node->lft, val);
        else if (val > node->value)
            node->rgt = insertnode(node->rgt, val);
        else
            return node;
        
        node->hgt = 1 + max(getheight(node->lft), getheight(node->rgt));
        
        int bal = getbal(node);
        
        if (bal > 1 && val < node->lft->value)
            return rightrot(node);
        
        if (bal < -1 && val > node->rgt->value)
            return leftrot(node);
        
        if (bal > 1 && val > node->lft->value) {
            node->lft = leftrot(node->lft);
            return rightrot(node);
        }
        
        if (bal < -1 && val < node->rgt->value) {
            node->rgt = rightrot(node->rgt);
            return leftrot(node);
        }
        
        return node;
    }
    
    void insert(int val) {
        root = insertnode(root, val);
    }
    
    void inorderprint(Node* node) {
        if (node != nullptr) {
            inorderprint(node->lft);
            cout << node->value << " ";
            inorderprint(node->rgt);
        }
    }
    
    void displaytree() {
        inorderprint(root);
        cout << endl;
    }
};

int main() {
    cout << "Task 2: Insert 55 and Perform Left Rotaton on Root" << endl;
    cout << "===================================================" << endl;
    
    AVLtree tree;
    
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    
    cout << "\nOrignal AVL tree: ";
    tree.displaytree();
    
    cout << "\nInserting value 55 into the tree..." << endl;
    tree.insert(55);
    
    cout << "Tree after inserting 55 (before left rotaton on root): ";
    tree.displaytree();
    
    cout << "\nPerforming left rotaton on the root node..." << endl;
    tree.root = tree.leftrot(tree.root);
    
    cout << "Tree after left rotaton on root: ";
    tree.displaytree();
    
    cout << "\nFinal tree height: " << tree.getheight(tree.root) << endl;
    
    return 0;
}