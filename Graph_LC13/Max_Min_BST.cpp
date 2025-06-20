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
Node* Min(Node* root){
  Node* temp=root;

  while(temp->left!=NULL){
    temp=temp->left;
  }  

  return temp;
}
Node* Max(Node* root){
    Node* temp=root;

    while(temp->right!=NULL){
        temp=temp->right;
    }

    return temp;
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
Node* deleteFromBst(Node* root, int val){
    //base case
    if(root == NULL){
        return root;
    }

    //base case(u got the root)
    if(root->root==val){
        //0 child
        if(root->left == NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //1child
        //left child
        if(root->left !=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }

        //right child
         if(root->right !=NULL && root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }

        //2child
        if(root->left != NULL && root->right !=NULL){
            int min=Min(root->right)->root;
            root->root=min;
            root->right=deleteFromBst(root->right,min);
            return root;
        }
    }
    else if(root->root > val){
        root->left=deleteFromBst(root->left,val);
        return root;
    }
    else{
        root->right=deleteFromBst(root->right,val);
        return root;
    }

    return root;
}
int main()
{
    Node* root = NULL;

    cout << "Enter the data to build the tree: ";
    takeInput(root);

    cout << "The minimum value is: ";
    cout << Min(root)->root;

    cout << "\nThe maximum value is: ";
    cout << Max(root)->root;

    // Delete a node
    int val;
    cout << "\nEnter value to delete: ";
    cin >> val;
    root = deleteFromBst(root, val);

    // Inorder traversal to show final tree
    cout << "\nTree after deletion (inorder): ";
    function<void(Node*)> inorder = [&](Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->root << " ";
        inorder(node->right);
    };
    inorder(root);

    return 0;
}
