#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int performOperation(char op, int a, int b) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
    }
    return 0;
}

int evaluatePrefix(string exp) {
    stack<int> s;
    
    for(int i = exp.length() - 1; i >= 0; i--) {
        if(isdigit(exp[i])) {
            s.push(exp[i] - '0');
        } else {
            int val1 = s.top(); 
            s.pop();
            int val2 = s.top(); 
            s.pop();
            
            int result = performOperation(exp[i], val1, val2);
            s.push(result);
        }
    }
    return s.top();
}

int main() {
    string prefix = "-+2*3549";
    
    cout << "Prefix Expression: " << prefix << endl;
    cout << "Result: " << evaluatePrefix(prefix) << endl;
    
    return 0;
}