#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Call {
    string name;
    string number;
    int duration;
};

class CallHistory {
    stack<Call> callStack;
public:
    void push(string name, string number, int duration) {
        Call c;
        c.name = name;
        c.number = number;
        c.duration = duration;
        callStack.push(c);
        display();
    }
    
    void pop() {
        if(!callStack.empty()) {
            callStack.pop();
            cout << "Call removed\n";
            display();
        } else {
            cout << "No calls to remove\n";
        }
    }
    
    void top() {
        if(!callStack.empty()) {
            Call c = callStack.top();
            cout << "Last call: " << c.name << " - " << c.number << " (" << c.duration << "s)\n";
        } else {
            cout << "No calls\n";
        }
    }
    
    bool empty() {
        return callStack.empty();
    }
    
    void display() {
        if(callStack.empty()) {
            cout << "Call history empty\n";
            return;
        }
        stack<Call> temp = callStack;
        cout << "\nCall History:\n";
        while(!temp.empty()) {
            Call c = temp.top();
            cout << c.name << " - " << c.number << " (" << c.duration << "s)\n";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    CallHistory ch;
    
    ch.push("John", "1234567890", 120);
    ch.push("Alice", "9876543210", 45);
    ch.push("Bob", "5551234567", 300);
    
    ch.top();
    ch.pop();
    ch.top();
    
    cout << "Is empty? " << (ch.empty() ? "Yes" : "No") << endl;
    
    return 0;
}