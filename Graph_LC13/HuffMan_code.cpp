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

class cmp{
    public:
    bool operator()(Node* a, Node* b){
        return a->root> b->root;
    }
};

void traverse(Node* root,vector<string>&ans,string temp){
    //base case
    if(root->left == NULL && root->right == NULL){
        ans.push_back(temp);
        return;
    }

    traverse(root->left,ans,temp+'0');
    traverse(root->right,ans,temp+'0'); 
}

vector<string> huffmanCode(string s,vector<int>f,int N){
    priority_queue<Node*,vector<Node*>,cmp>pq;

    for(int i=0;i<N;i++){
        Node* temp=new Node(f[i]);
        pq.push(temp);
    }

    while(pq.size()>1){
        Node* left=pq.top();
        pq.pop();

        Node* right=pq.top();
        pq.pop();

       Node* newN=new Node(left->root+right->root);
       newN->left=left;
       newN->right=right;
       pq.push(newN); 
    }

    Node* root=pq.top();
    vector<string> ans;
    string temp=" ";
    traverse(root,ans,temp);
    return ans;
}
int main() {
    int N;
    cout << "Enter number of characters: ";
    cin >> N;

    string s = "";
    vector<int> freq(N);

    cout << "Enter characters: ";
    for (int i = 0; i < N; i++) {
        char ch;
        cin >> ch;
        s += ch;
    }

    cout << "Enter frequencies: ";
    for (int i = 0; i < N; i++) {
        cin >> freq[i];
    }

    vector<string> codes = huffmanCode(s, freq, N);

    cout << "\nHuffman Codes:\n";
    for (int i = 0; i < N; i++) {
        cout << s[i] << ": " << codes[i] << endl;
    }

    return 0;
}
