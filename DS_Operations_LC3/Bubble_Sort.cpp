#include<iostream>
using namespace std;
void BubbleSort(int D[],int N){
    int PTR,temp,K;
    for(K=1;K<=N-1;K++){
        PTR=0;
        while(PTR<N-K){
            if(D[PTR]>D[PTR+1]){
                temp=D[PTR];
                D[PTR]=D[PTR+1];
                D[PTR+1]=temp;
            }
            PTR=PTR+1;
        }
    }
}
int main()
{
    int data[50];
    int N;
    cout<<"Please enter the amount to element u want: ";
    cin>>N;

    cout<<"Please enter your data: ";
    for(int i = 0;i < N;i++){
        cin>>data[i];
    }

    BubbleSort(data,N);

    cout<<"after sorting :"<<endl;
    for(int i=0;i<N;i++){
        cout<<data[i]<<" ";
    }
}