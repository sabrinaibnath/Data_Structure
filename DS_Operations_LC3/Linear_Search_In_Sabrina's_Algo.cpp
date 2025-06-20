#include<iostream>
using namespace std;
int Linear_Search(int b[],int N,int Item){
    int Loc=-1;

    for(int i=0;i<N;i++){
        if(b[i]==Item){
            Loc=i+1;
            break;
        }
    }
    return Loc;

}
int main()
{
    int data[50];
    int N,Item,Loc;

    cout<<"please the number of element: ";
    cin>>N;

    cout<<"please enter the item u are looking for: ";
    cin>>Item;

    for(int i=0;i<N;i++){
        int h;
        cin>>h;
        data[i]=h;
    }
    Loc=Linear_Search(data,N,Item);

    if(Loc==-1){
        cout<<"baby what u are looking for it's not here"<<endl;
    }
    else{
        cout<<"baby u have got it right, it's in location: "<<Loc<<endl;
    }
}