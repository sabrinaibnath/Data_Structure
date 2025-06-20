#include<bits/stdc++.h>
using namespace std;

//creating a node class(1st step)
class Node{
       public:
       //here we will have the variables that will keep the data
       int root;// i have created a variable named root to keep the value of a root node
       Node* left;// created a left child (data_type * variable_name the syntex of pointer)
       Node* right;// created a right child

       //now creating a constructor to assign the value in the variable

       Node(int d){
              this ->root=d;
              this ->left=NULL;//null cause when a node is created it is a child and it does not have child to point
              this ->right=NULL;
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

void LevelOrderTraversal_linear(Node* root){
       queue<Node*>q;
       q.push(root);

       while(!q.empty()){
              Node* temp=q.front();
              cout<< temp->root <<" ";
              q.pop();

              if(temp->left){
                     q.push(temp->left);
              }
              if(temp->right){
                     q.push(temp->right);
              }
       }
}

void LevelOrderTraversal(Node* root){
       queue<Node*>q;
       q.push(root);
       q.push(NULL);

       while(!q.empty()){
              Node* temp=q.front();
              q.pop();

              if(temp==NULL){//puraton level shesh hoiyeche bondhu
                     cout<<endl;
                     if(!q.empty()){// jodi kono itam theke o jai tahole
                            q.push(NULL);
                     }
              }
              else{
              cout<< temp->root <<" ";
              if(temp->left){
                     q.push(temp->left);
              }
              if(temp->right){
                     q.push(temp->right);
              }
              }
       }
}

int main()
{
       Node* root=NULL;

       //creating a Tree
       root=buildTree(root);


       //level order traversal
       LevelOrderTraversal_linear(root);

       cout<<endl;
       

       LevelOrderTraversal(root);

       return 0;
}