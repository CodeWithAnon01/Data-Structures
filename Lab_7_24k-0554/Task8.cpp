#include <iostream>
#include <string>
using namespace std;

struct Order {
    int orderID;
    string customerName;
    int totalPrice;
};

void swapOrders(Order &first, Order &second) {
    Order temp = first;
    first = second;
    second = temp;
}

int divideByPrice(Order orders[], int start, int end) {
    int pivotPrice = orders[end].totalPrice;
    int boundary = start - 1;
    
    for (int current = start; current < end; current++) {
        if (orders[current].totalPrice <= pivotPrice) {
            boundary++;
            swapOrders(orders[boundary], orders[current]);
        }
    }
    
    swapOrders(orders[boundary + 1], orders[end]);
    return boundary + 1;
}

void performQuickSort(Order orders[], int start, int end) {
    if (start < end) {
        int pivotPosition = divideByPrice(orders, start, end);
        
        performQuickSort(orders, start, pivotPosition - 1);
        performQuickSort(orders, pivotPosition + 1, end);
    }
}

void displayOrderList(Order orders[], int count) {
    cout << "\nSorted Orders by Total Price (Ascending):\n";
    cout << "=============================================\n";
    cout << "Order ID\tCustomer Name\tTotal Price\n";
    cout << "=============================================\n";
    
    for (int i = 0; i < count; i++) {
        cout << orders[i].orderID << "\t\t" 
             << orders[i].customerName << "\t\t" 
             << orders[i].totalPrice << endl;
    }
}

int main() {
    int numberOfOrders;
    
    cout << "Enter number of orders: ";
    cin >> numberOfOrders;
    
    Order* companyOrders = new Order[numberOfOrders];
    
    cout << "\nEnter order details:\n\n";
    
    for (int i = 0; i < numberOfOrders; i++) {
        cout << "Enter details for Order " << i + 1 << ":\n";
        cout << "Order ID: ";
        cin >> companyOrders[i].orderID;
        cout << "Customer Name: ";
        cin >> companyOrders[i].customerName;
        cout << "Total Price: ";
        cin >> companyOrders[i].totalPrice;
        cout << endl;
    }
    
    performQuickSort(companyOrders, 0, numberOfOrders - 1);
    
    displayOrderList(companyOrders, numberOfOrders);
    
    delete[] companyOrders;
    
    return 0;
}