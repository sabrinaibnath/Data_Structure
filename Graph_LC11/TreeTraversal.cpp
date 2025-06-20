#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
     Node* left;
     Node* right;
    
    Node(int v){
        data=v;
        left=NULL;
        right=NULL;
    }
};

void PreOrder( Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);

}
void InOrder( Node* root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);

}
void PostOrder( Node* root){
    if(root==NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
    
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    PreOrder(root);
    cout<<endl;
    cout<<"Inorder"<<endl;
    InOrder(root);
    cout<<endl;
    cout<<"POstorder"<<endl;
    PostOrder(root);
    return 0;

}