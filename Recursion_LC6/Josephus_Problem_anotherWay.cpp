#include<bits/stdc++.h>
using namespace std;

int Josephus(int n,int k){
    if(n==1){
        return 1;
    }
    if(n%2==0){
        return 2*Josephus(n/2,k)-1;
    }
    if(n%2!=0){
       return 2*Josephus(n/2,k)+1;
    }
    return 0;
}

int main()
{
    int n,k;
    cin>>n>>k;

    cout<<Josephus(n,k);
}