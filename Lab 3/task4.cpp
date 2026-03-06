#include <iostream>
#include <string>
using namespace std;

struct CharNode {
    char ch;
    CharNode* next;
};

CharNode* buildList(string word) {
    CharNode* h = nullptr;
    CharNode* tail = nullptr;
    for (char c : word) {
        CharNode* nd = new CharNode();
        nd->ch = c;
        nd->next = nullptr;
        if (!h) { h = tail = nd; }
        else { tail->next = nd; tail = nd; }
    }
    return h;
}

bool isPalindrme(CharNode* h) {
    string s = "";
    CharNode* tmp = h;
    while (tmp) {
        s += tmp->ch;
        tmp = tmp->next;
    }
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

int main() {
    string word;
    cout << "enter a word: ";
    cin >> word;

    CharNode* head = buildList(word);

    if (isPalindrme(head))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
