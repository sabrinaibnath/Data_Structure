#include<bits/stdc++.h>
using namespace std;

int prefixE(string s){
    stack<int>t;

     int d=s.length()-1;
    for(int i=d;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            t.push(s[i]-'0');
        }
        else{
            int second=t.top();
            t.pop();
            int first=t.top();
            t.pop();

            if (s[i] == '+') {
                t.push(first + second);
            } else if (s[i] == '-') {
                t.push(second-first);  // Fix: Ensure correct order
            } else if (s[i] == '*') {
                t.push(second* first);
            } else if (s[i] == '/') {
                t.push(second/first );  // Fix: Ensure correct order
            } else if (s[i] == '^') {
                t.push(pow(second,first));
            }
        }
    }
    return t.top();
}

int main()
{
   string s;
   cin>>s;
   cout<<prefixE(s); 
}