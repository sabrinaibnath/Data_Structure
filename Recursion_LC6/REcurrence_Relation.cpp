#include<bits/stdc++.h>
using namespace std;
int relation(int p){
    if(p==0){
        return 10000;
    }
    return relation(p-1)+0.05*relation(p-1);
}

int main()
{
    int n;
    cin>>n;

    cout<<relation(n);
}