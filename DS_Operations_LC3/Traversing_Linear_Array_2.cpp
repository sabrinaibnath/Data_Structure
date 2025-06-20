//Find the number NUM of years during which more than 300 automobiles were sold.
#include<iostream>
using namespace std;

int Traversal(int b[],int L){
    int NUM=0;
    for(int i=0;i<L;i++){
        if(b[i]>300){
            NUM++;
        }
    }
    return NUM;
}
int main()
{
    int UB,LB,LENGTH;
    
    cout<<"Please enter the starting year: "<<endl;
    cin>>LB;

    cout<<"Please enter the ending year: "<<endl;
    cin>>UB;

    LENGTH=UB-LB+1;
    int AUTO[LENGTH];

    for(int i=0;i<LENGTH;i++){
        int j;
        cin>>j;
        AUTO[i]=j;
    }

    int result=Traversal(AUTO,LENGTH);

    cout<<"Numbers of automobiles sold :"<<result<<endl;
}