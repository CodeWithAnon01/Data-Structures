#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^';
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    
    for(int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        if(isalnum(c)) {
            postfix += c;
        }
        else if(c == '(') {
            s.push(c);
        }
        else if(c == ')') {
            while(!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if(!s.empty()) s.pop();
        }
        else {
            while(!s.empty() && s.top() != '(' && 
                  (precedence(s.top()) > precedence(c) || 
                   (precedence(s.top()) == precedence(c) && !isRightAssociative(c)))) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    
    while(!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    
    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << infixToPostfix(infix) << endl;
    
    return 0;
}