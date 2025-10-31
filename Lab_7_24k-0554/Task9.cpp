#include <iostream>
using namespace std;

struct Transaction {
    int amount;
    int originalPosition;
};

int findMaximumAmount(Transaction transactions[], int count) {
    int maximum = transactions[0].amount;
    for (int i = 1; i < count; i++) {
        if (transactions[i].amount > maximum)
            maximum = transactions[i].amount;
    }
    return maximum;
}

void stableCountingSort(Transaction transactions[], int count, int digitPlace) {
    Transaction output[count];
    int frequency[10] = {0};
    
    for (int i = 0; i < count; i++)
        frequency[(transactions[i].amount / digitPlace) % 10]++;
    
    for (int i = 1; i < 10; i++)
        frequency[i] += frequency[i - 1];
    
    for (int i = count - 1; i >= 0; i--) {
        int digit = (transactions[i].amount / digitPlace) % 10;
        output[frequency[digit] - 1] = transactions[i];
        frequency[digit]--;
    }
    
    for (int i = 0; i < count; i++)
        transactions[i] = output[i];
}

void performStableRadixSort(Transaction transactions[], int count) {
    int maximumAmount = findMaximumAmount(transactions, count);
    
    for (int place = 1; maximumAmount / place > 0; place *= 10) {
        stableCountingSort(transactions, count, place);
    }
}

void displayTransactions(Transaction transactions[], int count, string stage) {
    cout << "\n" << stage << ":\n";
    cout << "================================\n";
    cout << "Amount\tOriginal Position\n";
    cout << "================================\n";
    
    for (int i = 0; i < count; i++) {
        cout << transactions[i].amount << "\t" 
             << transactions[i].originalPosition << endl;
    }
}

int main() {
    int numberOfTransactions;
    
    cout << "Enter number of transactions: ";
    cin >> numberOfTransactions;
    
    Transaction* bankTransactions = new Transaction[numberOfTransactions];
    
    cout << "\nEnter transaction amounts (integer values):\n";
    
    for (int i = 0; i < numberOfTransactions; i++) {
        cout << "Transaction " << i + 1 << " amount: ";
        cin >> bankTransactions[i].amount;
        bankTransactions[i].originalPosition = i + 1;
    }
    
    displayTransactions(bankTransactions, numberOfTransactions, "Before Sorting");
    
    performStableRadixSort(bankTransactions, numberOfTransactions);
    
    displayTransactions(bankTransactions, numberOfTransactions, "After Stable Radix Sort");
    
    cout << "\nStability Check:\n";
    cout << "Transactions with equal amounts maintain their original order.\n";
    
    delete[] bankTransactions;
    
    return 0;
}