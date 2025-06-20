#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;

    cout<<"enter the first string: "<<endl;
    cin>>s1;

    cout<<"enter the second sring: "<<endl;
    cin>>s2;


    stack<char>st1,st2;

    
    int size1=s1.length();
    int size2=s2.length();

    for(int i=0;i<size1;i++){
        if(!st1.empty() && s1[i]=='#'){
            st1.pop();
        }
        else if(s1[i]!='#'){
            st1.push(s1[i]);
        }
    }

    for(int i=0;i<size2;i++){
        if(!st2.empty() && s2[i]=='#'){
             st2.pop();
        }
         else if(s2[i]!='#'){
            st2.push(s2[i]);
        }
    }

    if(st1==st2){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }

    // while (!st1.empty() && !st2.empty()) {
    //         if (st1.top() != st2.top()) {
    //             return false;
    //         }
    //         st1.pop();
    //         st2.pop();
    //     }

    //     return st1.empty() && st2.empty();
    // }

    return 0;
}