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

bool isComplete(Node *Root){

    if(!Root){
        return true; // Empty tree is complete
    }

    queue<Node *> q;
    q.push(Root);
    bool flag = false; //tracks whether there was a null before a node

    while(!q.empty()){

        Node *temp = q.front();
        q.pop();

        if(temp == NULL){
            flag = true; // We've hit a NULL; all nodes after this must be NULL
        }

        else{
            if(flag){
                // We saw a NULL earlier, but now there's a node — not complete.
                return false;
            }

            q.push(temp->Left);
            q.push(temp->Right);
        }
    }
    return true;
}

int main(){

    Node *Root = new Node(1);
    Node *B = new Node(2);
    Node *C = new Node(3);
    Node *D = new Node(4);
    Node *E = new Node(5);
    Node *F = new Node(6);
    Node *G = new Node(7);
    
    Root->Left = B;
    Root->Right = C;

    B->Left = D;
    B->Right = E;

    C->Left = F;
    C->Right = G;

    if (isComplete(Root))
    {
        cout << "The tree is a complete binary tree." << endl;
    }
    else
    {
        cout << "The tree is not a complete binary tree." << endl;
    }

    return 0;
}