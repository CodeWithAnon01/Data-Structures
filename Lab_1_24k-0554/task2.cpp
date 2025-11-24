#include <iostream>
using namespace std;

class Box {
private:
    int* volume;
    
public:
    Box() {
        volume = new int;
        *volume = 0;
        cout << "Default constructor: volume = " << *volume << endl;
    }
    
    Box(int v) {
        volume = new int;
        *volume = v;
        cout << "Parameterized constructor: volume = " << *volume << endl;
    }
    
    Box(const Box& other) {
        volume = new int;
        *volume = *other.volume;
        cout << "Copy constructor: volume = " << *volume << " (Deep copy created)" << endl;
    }
    
    ~Box() {
        cout << "Destructor called for box with volume = " << *volume << endl;
        delete volume;
    }
    
    void setVolume(int v) {
        *volume = v;
    }
    
    int getVolume() const {
        return *volume;
    }
    
    void display() const {
        cout << "Volume: " << *volume << endl;
    }
};

int main() {
    cout << "=== a) Using default constructor ===" << endl;
    Box box1;
    box1.display();
    
    cout << "\n=== b) Using parameterized constructor ===" << endl;
    Box box2(100);
    box2.display();
    
    cout << "\n=== c) Using copy constructor ===" << endl;
    Box box3 = box2;
    box3.display();
    
    cout << "\n=== Changing volume of box3 ===" << endl;
    box3.setVolume(250);
    
    cout << "\nBox2 (original):" << endl;
    box2.display();
    
    cout << "\nBox3 (copied and modified):" << endl;
    box3.display();
    
    cout << "\n=== Demonstrating that original remains unchanged ===" << endl;
    cout << "Box2 volume: " << box2.getVolume() << " (unchanged)" << endl;
    cout << "Box3 volume: " << box3.getVolume() << " (modified)" << endl;
    
    cout << "\n=== Program ending - destructors will be called ===" << endl;
    
    return 0;
}