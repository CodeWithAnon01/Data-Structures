#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> s;
    
    for(int i = 0; i < exp.length(); i++) {
        if(isdigit(exp[i])) {
            s.push(exp[i] - '0');
        } else {
            int val2 = s.top(); 
            s.pop();
            int val1 = s.top(); 
            s.pop();
            
            switch(exp[i]) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.top();
}

int main() {
    string postfix = "23*54*+9-";
    
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Result: " << evaluatePostfix(postfix) << endl;
    
    return 0;
}