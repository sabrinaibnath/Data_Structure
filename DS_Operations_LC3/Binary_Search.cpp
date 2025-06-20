#include<iostream>
using namespace std;
int Binary_search(int b[],int LB,int UB,int Item){
    int Beg=LB;
    int End=UB;
    int mid=int((Beg+End)/2);

    while((Beg<=End) && (b[mid]!=Item)){
        if(Item<b[mid]){
            End=mid-1;
        }
        else{
            Beg=mid+1;
        }
         mid=int((Beg+End)/2);
    }
    if(b[mid]==Item){
        return mid+1;
    }
    else{
        return -1;
    }
}
int main()
{
  int data[50];
  int N,item,LB,UB,Loc;

  cout<<"Please enter the element: ";
  cin>>N;

  cout<<"Please enter the item: ";
  cin>>item;

  LB=0;
  UB=N-1;

for(int i=0;i<N;i++){
    cin>>data[i];
}
 Loc= Binary_search(data,LB,UB,item);

 if(Loc==-1){
    cout<<"it's not here"<<endl;
 }
 else{
    cout<<"it's in location "<<Loc;
 }
 return 0;
}