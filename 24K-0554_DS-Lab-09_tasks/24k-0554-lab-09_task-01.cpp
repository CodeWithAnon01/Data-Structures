#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int rollnum;
    Node* lft;
    Node* rgt;
    int hgt;
    
    Node(int val) {
        rollnum = val;
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
        
        if (val < node->rollnum)
            node->lft = insertnode(node->lft, val);
        else if (val > node->rollnum)
            node->rgt = insertnode(node->rgt, val);
        else
            return node;
        
        node->hgt = 1 + max(getheight(node->lft), getheight(node->rgt));
        
        int bal = getbal(node);
        
        if (bal > 1 && val < node->lft->rollnum)
            return rightrot(node);
        
        if (bal < -1 && val > node->rgt->rollnum)
            return leftrot(node);
        
        if (bal > 1 && val > node->lft->rollnum) {
            node->lft = leftrot(node->lft);
            return rightrot(node);
        }
        
        if (bal < -1 && val < node->rgt->rollnum) {
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
            cout << node->rollnum << " ";
            inorderprint(node->rgt);
        }
    }
    
    void displaytree() {
        inorderprint(root);
        cout << endl;
    }
};

int main() {
    cout << "Task 1: Inserting Student with Rol Number 15" << endl;
    cout << "=============================================" << endl;
    
    AVLtree tree;
    
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    
    cout << "\nOrignal tree with students: ";
    tree.displaytree();
    
    cout << "\n--- Walkthrogh of Inserting Student with Rol Number 15 ---" << endl;
    cout << "Step 1: Start at root (30)" << endl;
    cout << "Step 2: 15 < 30, go to left child (20)" << endl;
    cout << "Step 3: 15 < 20, go to left child (10)" << endl;
    cout << "Step 4: 15 > 10, go to right child (null)" << endl;
    cout << "Step 5: Insert 15 as right child of 10" << endl;
    cout << "Step 6: Update heights going back up the tree" << endl;
    cout << "Step 7: Node 20 becomes unbalenced (balance factor = -2)" << endl;
    cout << "Step 8: Perform left rotaton on node 20 to rebalence" << endl;
    
    tree.insert(15);
    
    cout << "\n--- After Inserting Student 15 ---" << endl;
    cout << "Tree: ";
    tree.displaytree();
    cout << "Height of AVL tree: " << tree.getheight(tree.root) << endl;
    
    cout << "\n--- Resulting AVL Tree Structure After Left Rotaton ---" << endl;
    cout << "         30" << endl;
    cout << "        /  \\" << endl;
    cout << "      15    40" << endl;
    cout << "     /  \\     \\" << endl;
    cout << "   10   20    50" << endl;
    
    return 0;
}