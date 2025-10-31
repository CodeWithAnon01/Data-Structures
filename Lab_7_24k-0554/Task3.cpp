#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    int price;
    string description;
    string availability;
};

void swapProducts(Product &first, Product &second) {
    Product temp = first;
    first = second;
    second = temp;
}

int partitionByPrice(Product products[], int start, int end) {
    int pivotPrice = products[end].price;
    int smallerIndex = start - 1;
    
    for (int current = start; current < end; current++) {
        if (products[current].price <= pivotPrice) {
            smallerIndex++;
            swapProducts(products[smallerIndex], products[current]);
        }
    }
    
    swapProducts(products[smallerIndex + 1], products[end]);
    return smallerIndex + 1;
}

void performQuickSort(Product products[], int start, int end) {
    if (start < end) {
        int pivotPosition = partitionByPrice(products, start, end);
        
        performQuickSort(products, start, pivotPosition - 1);
        performQuickSort(products, pivotPosition + 1, end);
    }
}

void displayProducts(Product products[], int count) {
    cout << "\nSorted Product List (by Price - Ascending):\n";
    cout << "------------------------------------------------------------\n";
    cout << "Name\t\tPrice\t\tAvailability\tDescription\n";
    cout << "------------------------------------------------------------\n";
    
    for (int i = 0; i < count; i++) {
        cout << products[i].name << "\t\t" 
             << products[i].price << "\t\t" 
             << products[i].availability << "\t\t" 
             << products[i].description << endl;
    }
}

int main() {
    int totalProducts = 3;
    Product inventory[3];
    
    cout << "Enter details of " << totalProducts << " products:\n\n";
    
    for (int i = 0; i < totalProducts; i++) {
        cout << "Product " << i + 1 << " name: ";
        cin >> inventory[i].name;
        cout << "Price: ";
        cin >> inventory[i].price;
        cin.ignore();
        cout << "Description: ";
        getline(cin, inventory[i].description);
        cout << "Availability (in stock / out of stock): ";
        getline(cin, inventory[i].availability);
        cout << endl;
    }
    
    performQuickSort(inventory, 0, totalProducts - 1);
    
    displayProducts(inventory, totalProducts);
    
    return 0;
}