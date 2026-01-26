#include <iostream>
using namespace std;

class BankAccount {
public:
    double bal;

    BankAccount() {
        bal = 0.0;
    }

    BankAccount(double initBal) {
        bal = initBal;
    }

    BankAccount(const BankAccount& other) {
        bal = other.bal;
    }

    void deduct(double amt) {
        bal -= amt;
    }

    void show() {
        cout << "Balance: $" << bal << endl;
    }
};

int main() {
    BankAccount acc1;
    cout << "acc1 ";
    acc1.show();

    BankAccount acc2(1000);
    cout << "acc2 ";
    acc2.show();

    BankAccount acc3 = acc2;
    acc3.deduct(200);
    cout << "acc3 after deducting 200: ";
    acc3.show();
    cout << "acc2 still: ";
    acc2.show();

    return 0;
}
