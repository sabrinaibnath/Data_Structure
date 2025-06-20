#include<bits/stdc++.h>
using namespace std;

int main(){
    char ch;
    int mismatch = 0;
    stack<char> s;
    queue<char> q;
    while(cin.peek()!='\n'){
        cin >> ch;
        if(isalpha(ch)){
            s.push(ch);
            q.push(ch);
        }
    }

    while(!s.empty() && !q.empty()){
        if(toupper(s.top()) != toupper(q.front())){
            mismatch++;
            break;
        }
        s.pop();
        q.pop();
    }
    if(mismatch == 0){
        cout << "Palindrome" << endl;
    }
    else{
        cout << "Not a Palindrome";
    }
    
    return 0;
}