#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void Insertion_Sort(int d[],int n){
    int temp=0,j=0;
    for(int i=1;i<n;i++){
       temp=d[i];
       j=i-1;
       while(j>=0 && d[j]>temp){
        d[j+1]=d[j];
        j=j-1;
        d[j+1]=temp;
       }
    }
}
int main()
{
 int n;
 cin>>n;
 int d[n];
 for(int i=0;i<n;i++){
    cin>>d[i];
 }

 int item;
 cin>>item;
 for(int i=0;i<n;i++){
    if(d[i]==item){
        cout<<i<<endl;
        return 0;
    }
    else{
     if(item>d[i] && item<d[i+1]){
      int h=i;
        cout<<h+1;
     }
    }
 }

}