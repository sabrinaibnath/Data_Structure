#include<iostream>
using namespace std;
void Selection_Sort(int data[],int N){
    int min,temp;
    for(int i=0;i<N-1;i++){
        min=i;
        for(int j=i+1;j<N;j++){
            if(data[j]<data[min]){
                min=j;
            }
        }
      
            temp=data[i];
            data[i]=data[min];
            data[min]=temp;
    }
}
int main()
{
    int data[50];
    int N;

    cout<<"enter the number of element: ";
    cin>>N;

    cout<<"enter ur array: "<<endl;
    for(int i=0;i<N;i++){
        int h;
        cin>>h;
        data[i]=h;
    }

    Selection_Sort(data,N);

    cout<<"After sorting: "<<endl;
    for(int i=0;i<N;i++){
        cout<<data[i]<<" ";
    }
}