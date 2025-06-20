#include<bits/stdc++.h>
#define N 20
using namespace std;

class Queue{
    int *arr;
    int front,rare;
    public:
    Queue(){
      arr=new int[N];
      front=-1;
      rare=-1;
    }

    void Push(int x){
        if(rare==N-1){
            cout<<"Queue overflow"<<endl;
            return;
        }
        rare++;
        arr[rare]=x;
        if(front==-1){
            front++;
        }
    }

    void pop(){
       if(front==-1 || front>rare){
        cout<<"queue underflow"<<endl;
        return;
       }
       front++;
    }

    int peek()
    {
         if(front==-1 || front>rare){
        cout<<"queue underflow"<<endl;
        return -1;
       }
       return arr[front];
    }

    bool empty(){
        return front==-1 || front>rare;
    }
};

int main()
{
    Queue q;
    q.Push(1);
    q.Push(2);
    q.Push(3);
    q.Push(4);
    
    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();

    return 0;

}