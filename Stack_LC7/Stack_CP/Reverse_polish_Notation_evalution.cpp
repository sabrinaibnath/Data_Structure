#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string& s : tokens){
            // when only digit then push it in the stack
            if(s!="+" && s!="-" && s!="*" && s!="/")  st.push(stoi(s));
            else{
                // when operator comes then pop two element from stack
                int second = st.top(); st.pop();
                int first = st.top(); st.pop();
                
                // for +
                if(s == "+") st.push(first+second);
                // for -
                else if(s == "-") st.push(first-second);
                // for *
                else if(s == "*") st.push(first*second);
                // for /
                else st.push(first / second);
            }
        }
        // only one num remain in the stack that is our answer so return it
        return st.top();
    }

int main() {
    vector<string> s = {"2", "1", "+", "3", "*"};  // Input infix expression
  
    int result = evalRPN(s);
    cout << "Result: " << result << endl;

    return 0;
}
