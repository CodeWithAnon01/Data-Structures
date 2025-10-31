#include <iostream>
using namespace std;

void sortBySpecificDigit(int productIDs[], int count, int digitPlace) {
    int output[count];
    int frequency[10] = {0};
    
    for (int i = 0; i < count; i++)
        frequency[(productIDs[i] / digitPlace) % 10]++;
    
    for (int i = 1; i < 10; i++)
        frequency[i] += frequency[i - 1];
    
    for (int i = count - 1; i >= 0; i--) {
        int digit = (productIDs[i] / digitPlace) % 10;
        output[frequency[digit] - 1] = productIDs[i];
        frequency[digit]--;
    }
    
    for (int i = 0; i < count; i++)
        productIDs[i] = output[i];
}

void performRadixSort(int productIDs[], int count) {
    for (int place = 1; place <= 10000; place *= 10) {
        sortBySpecificDigit(productIDs, count, place);
        
        cout << "\nAfter sorting by digit at place " << place << ":\n";
        for (int i = 0; i < count; i++) {
            cout << productIDs[i] << " ";
        }
        cout << endl;
    }
}

void displayProducts(int productIDs[], int count, string stage) {
    cout << "\n" << stage << ":\n";
    cout << "========================\n";
    for (int i = 0; i < count; i++) {
        cout << productIDs[i] << " ";
    }
    cout << "\n========================\n";
}

int main() {
    int totalProducts = 20;
    int inventory[20];
    
    cout << "Enter " << totalProducts << " product IDs (each a 5-digit integer):\n\n";
    
    for (int i = 0; i < totalProducts; i++) {
        cout << "Product " << i + 1 << " ID: ";
        cin >> inventory[i];
    }
    
    displayProducts(inventory, totalProducts, "Before Sorting");
    
    cout << "\n========================================";
    cout << "\nDigit-by-Digit Sorting Process:";
    cout << "\n========================================";
    
    performRadixSort(inventory, totalProducts);
    
    displayProducts(inventory, totalProducts, "Final Sorted Product IDs");
    
    return 0;
}