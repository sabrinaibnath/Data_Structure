#include<bits/stdc++.h>
using namespace std;
void printEvenIndices(vector<int>&v, int in){
     if(in<0){
          return ;
     }
     cout<<v[in]<<" ";
     printEvenIndices(v,in-2);
}
int main()
{
    int n;
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int in;
    if(n%2==0){
         in=n-2;
    }
    else{
        in=n-1;
    }
    printEvenIndices(v,in);
}