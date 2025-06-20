#include<iostream>
using namespace std;
void Deleting(int b[],int &N,int K){

    for(int j=K;j<=N-1;j++){
        b[j]=b[j+1];
    }
    N=N-1;
}
int main()
{
    int arr[50];

    int N,K;

    cout<<"enter the number of element please: ";
    cin>>N;

    cout<<"Please enter the location: ";
    cin>>K;

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    Deleting(arr,N,K-1);

    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}