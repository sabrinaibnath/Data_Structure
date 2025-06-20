#include<iostream>
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
    int data[50];
    int N;
    cout<<"please enter the length of ur array: ";
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>data[i];
    }

    Insertion_Sort(data,N);

    cout<<"after sorting: "<<endl;
    for(int i=0;i<N;i++){
        cout<<data[i]<<" ";
    }
}