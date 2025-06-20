#include<iostream>
using namespace std;

void Count_Sort(int data[],int N){
    //first we will get the largest element from the array
    int max=0;
    for(int i=0;i<N;i++){
        if(data[i]>max){
            max=data[i];
        }
    }
    //now we are creating our count array where the count of each element will be stored
    int count[max+1]={0};

    for(int i=0;i<N;i++){
        count[data[i]]++;
    }

    //now we will modify our count array 

    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];
    }
   //creating a output that will contain the position of elements after counting and decrement
    int output[N];

    for(int i=N-1;i>=0;i--){
        output[--count[data[i]]]=data[i];
    }
    //putting the sorted array in the main array
    for(int i=0;i<N;i++){
        data[i]=output[i];
    }
}
int main()
{
    int data[50],N;

    cout<<"enter the length of ur array: ";
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>data[i];
    }

    Count_Sort(data,N);


    cout<<"after sorting array: "<<endl;
    for(int i=0;i<N;i++){
        cout<<data[i]<<" ";
    }
}