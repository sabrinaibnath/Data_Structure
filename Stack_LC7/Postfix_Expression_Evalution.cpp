#include<bits/stdc++.h>
using namespace std;

int Evalution(vector<string>& s){
    stack<int> st;

    for(string& word:s){
            // when only digit then push it in the stack
            if(word!="+" && word!="-" && word!="*" && word!="/")  st.push(stoi(word));
            else{
                // when operator comes then pop two element from stack
                int second = st.top(); st.pop();
                int first = st.top(); st.pop();
                
                // for +
                if(word == "+") st.push(first+second);
                // for -
                else if(word == "-") st.push(first-second);
                // for *
                else if(word == "*") st.push(first*second);
                // for /
                else st.push(first / second);
            }
        }
        // only one num remain in the stack that is our answer so return it
        return st.top();
}

int main()
{
    vector<string> arr={"2","3","1","*","+","9","-"};
    cout<<Evalution(arr);
    return 0;
}