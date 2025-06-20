#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int Value;
        Node *Left, *Right;
        Node(int Value){
            this->Value = Value;
            this->Left = NULL;
            this->Right = NULL;
        }
};

void Insert(Node *&Root, int Value){ //Passing reference to a pointer

    Node *newNode = new Node(Value);
    if(Root == NULL){
        Root = newNode;
        return;
    }
    queue<Node *> q;
    q.push(Root);

    while(!q.empty()){

        Node *Temp = q.front();
        q.pop();

        if(Temp->Left == NULL){

            Temp->Left = newNode;
            return;
        }
        else{
            q.push(Temp->Left);
        }
        if (Temp->Right == NULL){

            Temp->Right = newNode;
            return;
        }
        else{
            q.push(Temp->Right);
        }
    }

}

void levelorder(Node *node){
    if(node == NULL){
        cout << "Tree is empty.\n"; 
        return;
    }
    queue<Node *> q;
    q.push(node);
    while(!q.empty()){
        Node *Temp = q.front();
        q.pop();
        cout << Temp->Value << " ";
        if(Temp->Left){
            q.push(Temp->Left);
        }
        if(Temp->Right){
            q.push(Temp->Right);
        }
    }
    
}

int main(){

    Node *Root = NULL;
    Insert(Root, 1);
    Insert(Root, 2);
    Insert(Root, 3);
    Insert(Root, 4);
    Insert(Root, 5);
    Insert(Root, 6);
    Insert(Root, 7);
    
    cout << "Level-order traversal of the complete binary Tree: \n";
    levelorder(Root);


    return 0;
}