#include<bits/stdc++.h>
using namespace std;

int J(int n){
    string bin=bitset<32>(n).to_string();//convert 32 bit binary
    bin=bin.substr(bin.find('1')+1)+'1';//moving msb to lsb

    return bitset<32>(bin).to_ulong();

}

int main()
{
    int n;
    cin>>n;
    cout<<J(n);
}