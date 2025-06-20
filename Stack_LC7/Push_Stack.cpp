#include<bits/stdc++.h>
using namespace std;
#define maxstk 100
void PUSH(int stack[], int &top,int item){
    if(top==maxstk){
        cout<<"Overflow"<<endl;
        return;
    }
    else{
        top=top+1;
        stack[top]=item;
    }
}
int main()
{
    int stack[maxstk];
    int top=-1;

    PUSH(stack,top,10);
    PUSH(stack,top,20);

    cout<<"Top element: "<<stack[top]<<endl;
    return 0;
    
}