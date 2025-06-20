//reverse polish notation
#include<bits/stdc++.h>
using namespace std;
int precedence(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/' || c=='%'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1; 
    }
}
string Postfix(string s){
    stack<char>st;
    string r;
    int size=s.length();

    for(int i=0;i<size;i++){
        //printing operand
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            cout<<s[i];
            r+=s[i];
        }
        //checking opening bracket '('
        else if(s[i]=='('){
            st.push(s[i]);
        }
        //checking closing bracket and poping the elements
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='(' ){
                r+=st.top();
                cout<<st.top();
                st.pop();
            }
            //popping opening bracket
            if(!st.empty()){
                st.pop();
            }
        }
        else{
          //checking operator if incomiming<top operator
          while(!st.empty() && precedence(st.top())>=precedence(s[i])){
            r+=st.top();
            cout<<st.top();
            st.pop();
          }
          st.push(s[i]);
        }
    }
    while(!st.empty()){
            r+=st.top();
            st.pop();
    }
    return r;
}
int main(){
    string s;
    cin>>s;
    
    string j=Postfix(s);
    cout<<endl;
    cout<<"new ope: "<<j;
}