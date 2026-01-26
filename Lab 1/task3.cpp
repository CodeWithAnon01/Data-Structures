#include <iostream>
using namespace std;

class Box {
public:
    int* sz;

    Box(int s) {
        sz = new int(s);
    }

    Box(const Box& other) {
        sz = new int(*other.sz);
        cout << "deep copy done" << endl;
    }

    Box& operator=(const Box& other) {
        if (this == &other) return *this;
        delete sz;
        sz = new int(*other.sz);
        cout << "assignment deep copy done" << endl;
        return *this;
    }

    ~Box() {
        delete sz;
        cout << "box destroyed, size was: " << endl;
    }

    void showSize() {
        cout << "size = " << *sz << endl;
    }
};

int main() {
    Box b1(10);
    cout << "b1: ";
    b1.showSize();

    Box b2 = b1;
    cout << "b2 (copy of b1): ";
    b2.showSize();

    *b2.sz = 99;
    cout << "\nafter changing b2 size to 99:" << endl;
    cout << "b1: ";
    b1.showSize();
    cout << "b2: ";
    b2.showSize();

    Box b3(5);
    b3 = b1;
    cout << "\nb3 after assignment from b1: ";
    b3.showSize();

    return 0;
}
