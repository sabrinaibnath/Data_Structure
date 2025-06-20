#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left_Child;
    struct Node* right_Child;

    Node(int Value){
        data=Value;
        left_Child=NULL;
        right_Child=NULL;
    }
};

//function to print a tree 
void PreOrder(struct Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left_Child);
    PreOrder(root->right_Child);

}

int main()
{
   
   struct Node* root=new Node(1);
   root->left_Child=new Node(2);
   root->right_Child=new Node(3);

   PreOrder(root);

   return 0;
}