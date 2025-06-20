#include<bits/stdc++.h>
#define N 100
using namespace std;

class Stack{
    private:
    int arr[N],top;

    public:
    //to initialize an empty array
    Stack(){
        top=-1;
    }

    void push(int item){
         if(top>=N-1){
            cout<<"stack Overflow"<<endl;
         }
         else{
            top=top+1;
             arr[top]=item;
         }
    }

    int pop(){
        if(top<=-1){
        cout<<"stack Underflow"<<endl;
        return -1;
    }
    else{
      return arr[--top];
       }
    }

    bool isEmpty()
    {
        return top==-1;
    }

    bool isFull(){
        return top==N-1;
    }

    //retrive the recently added item
    int peek(){
        if(top<0){
            cout<<"the stack is empty"<<endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }

    void destroy(){
        top=-1;
    }
   

};
int main()
{
   Stack s;
   s.push(7);
   s.push(8);
   s.push(10);
   s.push(6);
  
  cout<<s.peek()<<endl;
  
  s.pop();
  cout<<s.peek()<<endl;
  
  return 0;
}