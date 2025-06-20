//enqueue:push element x in stack1
//dequeue:1.if both stack are empty print error.
         //2.if stack2 is empty then push everything from stack1 to stack2
         //pop from stack2

 #include<bits/stdc++.h>
 using namespace std;
 class Queue{
    stack<int>stack1,stack2;

    public:
    void Push(int x){
        stack1.push(x);
    }

    int pop(){
        if(stack1.empty() && stack2.empty()){
           cout<<"Queue is empty";
           return -1; 
        }
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int topvalue=stack2.top();
        stack2.pop();
        return topvalue;
    }
    int peek() {
        // If both stacks are empty, queue is empty
        if (stack1.empty() && stack2.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        // If stack2 is empty, transfer all elements from stack1 to stack2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        // Return the top of stack2 (front of the queue) without popping it
        return stack2.top();
    }


    bool empty(){
        if(stack1.empty() && stack2.empty()){
            return true;
        }
        else{
            return false;
        }
    }

 };
 int main()
 {
    Queue q;
    q.Push(2);
    q.Push(3);
    q.Push(4);

    int y=q.pop();

 
   cout<<y<<endl;
   return 0;
    
 }        