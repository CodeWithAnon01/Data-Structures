#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Node {
    string url;
    Node* next;
};

class BrowserHistory {
    Node* head;
    stack<string> historyStack;
    
public:
    BrowserHistory() {
        head = nullptr;
    }
    
    void visit(string url) {
        Node* newNode = new Node;
        newNode->url = url;
        newNode->next = head;
        head = newNode;
        historyStack.push(url);
    }
    
    void goBack(int steps) {
        for(int i = 0; i < steps && !historyStack.empty() && head != nullptr; i++) {
            historyStack.pop();
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void displayList() {
        cout << "\nLinked List (browsing history): ";
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->url << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    
    void displayStack() {
        cout << "Stack (back button): ";
        stack<string> temp = historyStack;
        while(!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
    
    string getCurrentPage() {
        if(head != nullptr) {
            return head->url;
        }
        return "No page";
    }
};

int main() {
    BrowserHistory browser;
    
    browser.visit("Google");
    browser.visit("Facebook");
    browser.visit("Twitter");
    browser.visit("LinkedIn");
    browser.visit("Instagram");
    
    cout << "After visiting 5 websites:\n";
    browser.displayList();
    browser.displayStack();
    cout << "Current page: " << browser.getCurrentPage() << endl;
    
    cout << "\nClicking back button twice:\n";
    browser.goBack(2);
    
    browser.displayList();
    browser.displayStack();
    cout << "Current page: " << browser.getCurrentPage() << endl;
    
    return 0;
}