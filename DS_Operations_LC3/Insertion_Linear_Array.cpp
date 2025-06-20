#include<iostream>
using namespace std;
void INSERT(int a[],int &N,int K,int ITEM){
    int j=N;

    while(j>=K){
        a[j+1]=a[j];
        j=j-1;
    }
    a[K]=ITEM;
    N=N+1;
}
int main(){
    int arr[50];

    int N,K,ITEAM;
    cout<<"Enter the number of element: ";
    cin>>N;
    cout<<"Enter the location: ";
    cin>>K;
    cout<<"Enter the ITEM: ";
    cin>>ITEAM;

    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    INSERT(arr,N,K,ITEAM);
   
   cout<<"the updated array is:"<<endl;
   for(int i=1;i<=N;i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;

   return 0;
}