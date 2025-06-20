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

Node* BST(vector<int>& graph){
    int s=graph.size();
    if(s==0){
        return NULL;
    }

    Node* root=new Node(graph[0]);
    queue<Node*> q;
    q.push(root);

    int i=1;
    while(i<s){
        Node* c=q.front();
        q.pop();

        //left child
        if(i<s){
            c->left=new Node(graph[i++]);
            q.push(c->left);
        }

        //right child
        if(i<s){
            c->right=new Node(graph[i++]);
            q.push(c->right);
        }
    }

    return root;
}
void LevelOrderTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL); // Level marker

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL); // Next level marker
            }
        } else {
            cout << temp->root << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}
int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = BST(arr);

    cout << "\nLevel Order Traversal of Complete Binary Tree:\n";
    LevelOrderTraversal(root);

    return 0;
}