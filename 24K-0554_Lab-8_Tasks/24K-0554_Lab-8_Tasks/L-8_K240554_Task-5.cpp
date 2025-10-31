#include <iostream>
using namespace std;

struct Product {
    int id;
    int quantity;
    Product* left;
    Product* right;
    Product(int pid, int qty) {
        id = pid;
        quantity = qty;
        left = right = nullptr;
    }
};

Product* insert(Product* root, int id, int qty) {
    if (!root) return new Product(id, qty);
    if (id == root->id) root->quantity += qty;
    else if (id < root->id) root->left = insert(root->left, id, qty);
    else root->right = insert(root->right, id, qty);
    return root;
}

Product* search(Product* root, int id) {
    if (!root || root->id == id) return root;
    if (id < root->id) return search(root->left, id);
    return search(root->right, id);
}

void findMax(Product* root, Product*& maxProduct) {
    if (!root) return;
    if (!maxProduct || root->quantity > maxProduct->quantity)
        maxProduct = root;
    findMax(root->left, maxProduct);
    findMax(root->right, maxProduct);
}

int main() {
    Product* root = nullptr;
    root = insert(root, 101, 20);
    root = insert(root, 102, 15);
    root = insert(root, 103, 25);

    int searchID = 102;
    Product* found = search(root, searchID);
    if (found)
        cout << "Product " << searchID << " found with quantity: " << found->quantity << endl;
    else
        cout << "Product not found." << endl;

    Product* maxProduct = nullptr;
    findMax(root, maxProduct);
    cout << "Product with highest quantity: ID " << maxProduct->id << " Qty " << maxProduct->quantity << endl;

    return 0;
}
