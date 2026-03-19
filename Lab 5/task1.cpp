#include <iostream>
#include <string>
using namespace std;

bool checkPalindrme(string s, int l, int r) {
    if (l >= r) return true;
    if (s[l] != s[r]) return false;
    return checkPalindrme(s, l+1, r-1);
}

int main() {
    string s;
    cout << "enter string: ";
    cin >> s;

    if (checkPalindrme(s, 0, s.size()-1))
        cout << "Yes, it is a palindrome" << endl;
    else
        cout << "No, not a palindrome" << endl;

    return 0;
}
