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

    cout<<"printing the BST: "<<endl;
    LevelOrderTraversal(root);

    return 0;
}