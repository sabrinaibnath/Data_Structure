//polish notation
#include <bits/stdc++.h>
using namespace std;

int Precedence(char c) {
    if (c == '^'){
        return 3;
    } 
    if (c == '*' || c == '/' || c == '%'){
        return 2;
    }
    if (c == '+' || c == '-'){
        return 1;
    }
    return -1;
}

string infixToPrefix(string s) {
    stack<char> d;
    string r;
    int size = s.length();

    // Reverse the string and swap '(' with ')'
    reverse(s.begin(), s.end());
    for (int i = 0; i < size; i++) {
        if (s[i] == '('){
            s[i] = ')';
        }
        else if (s[i] == ')'){
          s[i] = '(';
        } 
    }

    for (int i = 0; i < size; i++) {
       if (isalnum(s[i])) {  // Includes both letters and numbers
            r += s[i];
        } 

        else if (s[i] == '(') {
            d.push(s[i]);
        } 
        else if (s[i] == ')') {
            while (!d.empty() && d.top() != '(') {
                r += d.top();
                d.pop();
            }
            if (!d.empty()) d.pop(); // Pop '('
        } 
        else { // Operator case
            while (!d.empty() && Precedence(d.top()) >= Precedence(s[i])) {
                r += d.top();
                d.pop();
            }
            d.push(s[i]);
        }
    }

    // Pop remaining operators from the stack
    while (!d.empty()) {
        r += d.top();
        d.pop();
    }

    // Reverse the result to get prefix notation
    reverse(r.begin(), r.end());
    return r;
}

int main() {
    string s;
    cin >> s;
    cout << infixToPrefix(s) << endl;
    return 0;
}
