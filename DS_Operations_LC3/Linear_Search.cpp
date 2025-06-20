#include<iostream>
using namespace std;
int Linear_Search(int b[],int N,int Item){
    int Loc=0;
    b[N+1]=Item;
   while(b[Loc]!=Item){
    Loc=Loc+1;
   }
   if(Loc==N+1){
    return Loc=0;
   }
   else{
    return Loc+1;
   }
}
int main()
{
    int data[50];

    int N,Item,Loc;

    cout<<"Please enter the number of element: ";
    cin>>N;

    cout<<"please enter the item u are looking for: ";
    cin>>Item;
    for(int i=0;i<N;i++){
        cin>>data[i];
    }
    Loc=Linear_Search(data,N,Item);

    if(Loc==0){
        cout<<"It's not in here"<<endl;
    }
    else{
        cout<<"it's in Location: "<<Loc<<endl;
    }
    return 0;
}