#include<bits/stdc++.h>
using namespace std;
double relation(int n){
    if(n==0){
        return 135.00;
    }

    return relation(n-1)*1.5168;
}

int main()
{
    int n;
    cin>>n;

    cout<<relation(n);
}