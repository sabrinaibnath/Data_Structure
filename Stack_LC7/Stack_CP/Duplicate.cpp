#include<bits/stdc++.h>
using namespace std;
string RemoveDuplicate(string s){
    //we will store the last index of the characters in a vector whose size is 26 and initialized with 0
    vector<int> LastIndex(26,0);

    //storing the last index
    int size=s.length();
    for(int i=0;i<size;i++){
        LastIndex[s[i]-'a']=i;
    }

    vector<bool>seen(26,false);
    stack<char>st;

    for(int i=0;i<size;i++){
        int curr=s[i]-'a';
        if(seen[curr]){
            continue;
        }
        else{
            while(st.size()>0 && st.top()>s[i] && i<LastIndex[st.top()-'a']){
                seen[st.top()-'a']=false;
                st.pop();
            }
            st.push(s[i]);
            seen[curr]=true;
        }
    }

    string as="";
    while(st.size()>0){
        as+=st.top();
        st.pop();
    }
    reverse(as.begin(),as.end());

    return as;

}
int main()
{
     string s;
     cin>>s;
     cout<<RemoveDuplicate(s)<<endl;
     return 0;
}
