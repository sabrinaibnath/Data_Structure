#include<iostream>
#include<math.h>
using namespace std;
void Merge(int d[],int left,int mid,int right)
{
  int h=left;// to track the position of the left sub array 
  int i=left;//for tracking new array
  int j=mid+1;//to track the position of the right sub arrays

  int temp[right - left + 1]; 
     
  while(h <= mid && j <= right){
    if(d[h] <= d[j]){
        temp[i] = d[h];
        h++;
    }
    else{
       temp[i] = d[j];
        j++; 
    }
    i++;
  }

  if(h>mid){
    for(int k=j;k<=right;k++,i++){
        temp[i]=d[k];
    }
  }
  else{
    for(int k=h;k<=mid;k++,i++){
        temp[i]=d[k];
    }
  }

    for (int k = left; k <= right; k++) {//keeping the sorted array in the main array
        d[k] = temp[k];
    }

}
void MergeSort(int d[],int left,int right)
{
      if(left<right){
        int mid=floor((left+right)/2);
        MergeSort(d,left,mid);
        MergeSort(d,mid+1,right);
        Merge(d,left,mid,right);
      }
}
int main()
{
    int data[50];
    int N;
    cout<<"enter the length of ur array:";
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>data[i];
    }

    int left=0;
    int right=N-1;

   MergeSort(data,left,right);

   cout<<"after sorting the array"<<endl;
   for(int i=0;i<N;i++){
    cout<<data[i]<<" ";
   }
    
}
