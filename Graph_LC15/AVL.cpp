#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int root,height;
    Node* left;
    Node* right;

    Node(int d){
        root=d;
        height=1;
        left=NULL;
        right=NULL;
    }

};
// function to get the height
int heightOfNode(Node* root){
    if(root==NULL){
        return 0;
    }
    else{
        return root->height;
    }
}
// function to do right rotate
Node* rightRotate(Node* root){
    Node* l=root->left;
    Node* r=l->right;

    //perform rotation
    l->right=root;
    root->left=r;

    //update heights
    root->height=1+max(heightOfNode(root->left),heightOfNode(root->right));
    l->height=1+max(heightOfNode(l->left),heightOfNode(l->right));

    return l;

}

//function to do left rotation
Node* leftRotate(Node* root){
    Node* l=root->right;
    Node* r=l->left;

    //perform rotation
    l->left=root;
    root->right=r;

    //update heights
    root->height=1+max(heightOfNode(root->left),heightOfNode(root->right));
    l->height=1+max(heightOfNode(l->left),heightOfNode(l->right));

    return l;
}

int getBalance(Node* root){
    if(root==NULL){
        return 0;
    }
    else{
        return heightOfNode(root->left)-heightOfNode(root->right);
    }
}

Node* insert(Node* root, int key){

    //normal bst insertion

    if(root == NULL){
        Node* r=new Node(key);
        return r;
    }

    if(key< root->root){
        root->left=insert(root->left,key);
    }
    else if(key>root->root){
        root->right=insert(root->right,key);
    }
    else{
        return root;
    }
    
    root->height=1+max(heightOfNode(root->left),heightOfNode(root->right));

    int balance=getBalance(root);

     // Left Left Case 
    if (balance > 1 && key < root->left->root) 
        return rightRotate(root); 

    // Right Right Case 
    if (balance < -1 && key > root->right->root) 
        return leftRotate(root); 

    // Left Right Case 
    if (balance > 1 && key > root->left->root) { 
        root->left = leftRotate(root->left); 
        return rightRotate(root); 
    } 

    // Right Left Case 
    if (balance < -1 && key < root->right->root) { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 

    // Return the (unchanged) node pointer 
    return root; 
}
void preOrder(Node *root) { 
    if (root != NULL) { 
        cout << root->root << " "; 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 

// Driver Code 
int main() { 
    Node *root = NULL; 
    
    // Constructing tree given in the above figure 
    root = insert(root, 10); 
    root = insert(root, 20); 
    root = insert(root, 30); 
    root = insert(root, 40); 
    root = insert(root, 50); 
    root = insert(root, 25); 
    
    /* The constructed AVL Tree would be 
              30 
            /   \ 
          20     40 
         /  \      \ 
       10   25     50 
    */
    cout << "Preorder traversal : \n"; 
    preOrder(root); 
    
    return 0; 
}