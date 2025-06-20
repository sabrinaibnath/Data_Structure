#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1;
    cin>>s1;

    stack<char>st1;

    int size1=s1.length();

    for(int i=0;i<size1;i++){
        st1.push(s1[i]);
    }

    for(int i=0;i<size1;i++){
        cout<<st1.top();
        st1.pop();
    }

    return 0;
}