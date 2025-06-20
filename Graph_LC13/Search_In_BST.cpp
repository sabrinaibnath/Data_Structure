#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int root;
    Node* left;
    Node* right;

    Node(int d){
        root=d;
        left=NULL;
        right=NULL;
    }
};

bool SearchInBst(Node* root,int looking_For){
    //base case(if it's not found love)
    if(root==NULL){
        return false;
    }
    
    //base case (if it's found love)
    if(root->root==looking_For){
        return true;
    }

    //checking in left part
    if(root->root >looking_For){
        return SearchInBst(root->left,looking_For);
    }
    else{
        return SearchInBst(root->right,looking_For);
    }
}

Node* InsertIntoBst(Node* root,int data){
    //base case
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(root->root < data){
           root->right=InsertIntoBst(root->right,data);
        }
    else{
            root->left=InsertIntoBst(root->left,data);
        }

    return root;
 }
void takeInput(Node*& root){
    int data;
    cin>>data;

    while(data!=-1){
       root= InsertIntoBst(root,data);
        cin>>data;
    }
}

int main()
{
    Node* root=NULL;
    
    cout<<"Enter the data to build the tree: ";
    takeInput(root);
    
   int target;
   cout<<"please enter the node that u are looking for: ";
   cin>>target;

   cout<<SearchInBst(root,target);


    return 0;
}