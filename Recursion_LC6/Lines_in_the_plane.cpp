#include<bits/stdc++.h>
using namespace std;
int lines(int n){
    if(n==0){
      return 1;
    }

    return lines(n-1)+n;
}

int main()
{
    int n;
    cin>>n;
    cout<<lines(n);
}