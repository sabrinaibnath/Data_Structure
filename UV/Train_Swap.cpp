#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
             cin>>v[i];
        }

        int p,temp,k,count=0;

       for(k=1;k<=n-1;k++){
        p=0;
        while(p<n-k){
            if(v[p]>v[p+1]){
                temp=v[p];
                v[p]=v[p+1];
                v[p+1]=temp;
                count++;
            }
            p=p+1;
        }
    }
    cout<<count<<endl;
    }
    return 0;
}