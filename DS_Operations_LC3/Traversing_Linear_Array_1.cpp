//Print the contents of each element of DATA or Count the number of elements of DATA with a given property.
#include<iostream>
using namespace std;
void Traversal(int b[],int L,int LB){
    for(int i=0;i<L;i++){
        cout<<LB+i<<" in this year the automobiles sold :"<<b[i]<<endl;
    }
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
        cin>>AUTO[i];
    }

    Traversal(AUTO,LENGTH,LB);
}