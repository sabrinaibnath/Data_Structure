#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void Insertion_Sort(vector<float>& B){
    int n=B.size(),j=0;
    float temp=0;
    for(int i=1;i<n;i++){
       temp=B[i];
       j=i-1;
       while(j>=0 && B[j]>temp){
        B[j+1]=B[j];
        j=j-1;
        B[j+1]=temp;
       }
    }
}
void Bucket_Sort(float data[],int n){
    //creating array of empty bucket and initializing empty bucket 
    vector<float>B[n]={};


    // //initializing empty bucket
    // for(int i=0;i<n;i++){
    //     B[i]={};
    // }
    
    //putting items into respective bucket

    for (int i = 0; i < n; i++) {
        int index = (int)(n * data[i]);  
        B[index].push_back(data[i]);
    }

    for(int i=0;i<n;i++){
        Insertion_Sort(B[i]);
    }

    int index=0;
    for(int i=0;i<n;i++){
        for(float num:B[i]){
            data[index++]=num;
        }
    }
} 
int main()
{
   int n;
   cout<<"enter the length please: ";
   cin>>n;

   float data[n];

   for(int i=0;i<n;i++){
    cin>>data[i];
   } 


   Bucket_Sort(data,n); 


   cout<<"after sorting: ";
   for(int i=0;i<n;i++){
    cout<<data[i]<<" ";
   } 
}