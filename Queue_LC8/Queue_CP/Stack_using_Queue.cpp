#include<bits/stdc++.h>
using namespace std;

class Stack{
    int N;
    queue<int>q1,q2;
public:
    Stack(){
        N=0;
    }
    void push(int x){
        q2.push(x);
         N++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        queue<int>temp;
        temp=q1;
        q1=q2;
        q2=temp;
    }

    void pop(){
        q1.pop();
        N--;
    }

    int top(){
        return q1.front();
    }

    int size(){
        return N;
    }
};
int main()
{
    Stack st;

    st.push(1);
    st.push(2);
    cout<<st.top();
}