#include<bits/stdc++.h>
using namespace std;
int palindrome(vector<int>&v,int start,int end){
    if(start>=end){
        return 1;
    }

    if(v[start]!=v[end]){
        return 0;
    }

    return palindrome(v,start+1,end-1);

}
int main()
{
    int n;
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
         cin>>v[i];
    }
    

    int result=palindrome(v,0,n-1);

    if(result){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}