#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

Node* newNode(int v) {
    Node* n = new Node();
    n->val = v;
    n->next = nullptr;
    return n;
}

void printList(Node* h) {
    while (h) {
        cout << h->val;
        if (h->next) cout << " -> ";
        h = h->next;
    }
    cout << " -> NULL" << endl;
}

Node* separateEvenOdd(Node* h) {
    Node* evenHead = nullptr, *evenTail = nullptr;
    Node* oddHead = nullptr, *oddTail = nullptr;

    Node* curr = h;
    while (curr) {
        if (curr->val % 2 == 0) {
            if (!evenHead) { evenHead = evenTail = curr; }
            else { evenTail->next = curr; evenTail = curr; }
        } else {
            if (!oddHead) { oddHead = oddTail = curr; }
            else { oddTail->next = curr; oddTail = curr; }
        }
        curr = curr->next;
    }

    if (!evenHead) return oddHead;
    if (!oddHead) return evenHead;

    evenTail->next = oddHead;
    oddTail->next = nullptr;
    return evenHead;
}

int main() {
    int n;
    cout << "how many numbers: ";
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;
    cout << "enter numbers: ";
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        Node* nd = newNode(v);
        if (!head) { head = tail = nd; }
        else { tail->next = nd; tail = nd; }
    }

    cout << "original: ";
    printList(head);

    head = separateEvenOdd(head);

    cout << "after rearrange: ";
    printList(head);

    return 0;
}
