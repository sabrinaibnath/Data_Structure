#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
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
        sort(B[i].begin(),B[i].end());
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