#include<bits/stdc++.h>
using namespace std;
#define maxstk 100
void Pop(int stack[], int &top, int &item){
   if(top==-1){
        cout<<"Underflow"<<endl;
        return;
    }
    else{
        item=stack[top];
        top=top-1;
    }
}
int main()
{
    int stack[maxstk];
    int top=-1;
    int item;

    stack[++top] = 10;
    stack[++top] = 20;

    Pop(stack,top,item);
    cout << "Popped item: " << item << endl;

    Pop(stack,top,item);
    cout << "Popped item: " << item << endl;
    
    Pop(stack, top, item);  

    return 0;
    
}