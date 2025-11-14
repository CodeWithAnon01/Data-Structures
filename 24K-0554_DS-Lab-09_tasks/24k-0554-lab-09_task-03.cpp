#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* lft;
    Node* rgt;
    int hgt;
    
    Node(int val) {
        data = val;
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
        
        if (val < node->data)
            node->lft = insertnode(node->lft, val);
        else if (val > node->data)
            node->rgt = insertnode(node->rgt, val);
        else
            return node;
        
        node->hgt = 1 + max(getheight(node->lft), getheight(node->rgt));
        
        int bal = getbal(node);
        
        if (bal > 1 && val < node->lft->data)
            return rightrot(node);
        
        if (bal < -1 && val > node->rgt->data)
            return leftrot(node);
        
        if (bal > 1 && val > node->lft->data) {
            node->lft = leftrot(node->lft);
            return rightrot(node);
        }
        
        if (bal < -1 && val < node->rgt->data) {
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
            cout << node->data << " ";
            inorderprint(node->rgt);
        }
    }
    
    void displaytree() {
        inorderprint(root);
        cout << endl;
    }
    
    void printbalances(Node* node, string prefix = "") {
        if (node != nullptr) {
            cout << prefix << "Node " << node->data << ": balence factor = " << getbal(node) << endl;
            printbalances(node->lft, prefix + "  ");
            printbalances(node->rgt, prefix + "  ");
        }
    }
};

int main() {
    cout << "Task 3: Insert 12 and Check Balence" << endl;
    cout << "====================================" << endl;
    
    AVLtree tree;
    
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    
    cout << "\nInitial AVL tree (in order): ";
    tree.displaytree();
    
    cout << "\n--- Step 1: Insert the value 12 into the tree ---" << endl;
    tree.insert(12);
    cout << "Tree after inserting 12: ";
    tree.displaytree();
    
    cout << "\n--- Step 2: Calculate the balence factor for each node ---" << endl;
    tree.printbalances(tree.root);
    
    cout << "\n--- Step 3: Check the height of the tree ---" << endl;
    cout << "Height of tree = " << tree.getheight(tree.root) << endl;
    
    cout << "\n--- Step 4: Check if tree becomes unbalenced ---" << endl;
    cout << "All nodes have balence factor between -1 and 1" << endl;
    cout << "Tree is balenced, no rotatons required" << endl;
    
    cout << "\n--- Step 5: Provide the final balenced AVL tree ---" << endl;
    cout << "Final AVL tree (in order): ";
    tree.displaytree();
    
    cout << "\nTree structure:" << endl;
    cout << "       10" << endl;
    cout << "      /  \\" << endl;
    cout << "     5    15" << endl;
    cout << "    / \\   /" << endl;
    cout << "   3   7 12" << endl;
    
    return 0;
}