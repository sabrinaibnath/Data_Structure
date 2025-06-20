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

Node* buildTree(Node* root){
       cout<<"enter the data: "<<endl;
       int data;
       cin>>data;
       root=new Node(data);

       if(data==-1){
              return NULL;
       }
 
       cout<<"Enter data for inserting in left"<<" "<< data <<endl;
       root->left=buildTree(root->left);
       
       cout<<"Enter data for inserting in right"<<" "<< data <<endl;
       root->right=buildTree(root->right);


       return root;

}
void PreOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->root<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
int main()
{
   

     Node* root=NULL;

       //creating a Tree
    root=buildTree(root);
    cout<<endl<<"preOrder: ";
    PreOrder(root);
    
}