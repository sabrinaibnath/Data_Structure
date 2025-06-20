#include<bits/stdc++.h>
using namespace std;
void Shell_Sort(int A[],int n){
    int temp,gap,i,j;
    for(gap=n/2;gap>0;gap/=2){
        for(i=gap;i<n;i++){
            temp=A[i];
            for(j=i;j>=gap && A[j-gap]>temp;j-=gap){
                A[j]=A[j-gap];
            }
            A[j]=temp;
        }
    }

}
int main(){
    int n;
    cin>>n;
    int d[n];

    for(int i=0;i<n;i++){
        cin>>d[i];
    }

    Shell_Sort(d,n);

    cout<<"after sorting: ";

    for(int i=0;i<n;i++){
        cout<<d[i]<<" ";
    }

}