#include <iostream>
#include <vector>
using namespace std;

class BinaryTree {
public:
    vector<int> tree;

    void insert(int val) {
        tree.push_back(val);
    }
     
    
    void inorder(int index) {
         int s=tree.size();
        if (index >= s) return;

        // Left child
        inorder(2 * index + 1);
        // Root
        cout << tree[index] << " ";
        // Right child
        inorder(2 * index + 2);
    }

    void preorder(int index) {
         int s=tree.size();
        if (index >= s) return;

        cout << tree[index] << " ";
        preorder(2 * index + 1);
        preorder(2 * index + 2);
    }

    void postorder(int index) {
         int s=tree.size();
        if (index >= s) return;

        postorder(2 * index + 1);
        postorder(2 * index + 2);
        cout << tree[index] << " ";
    }
};

int main() {
    BinaryTree bt;

    // Insert values into binary tree
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);

    cout << "Inorder: ";
    bt.inorder(0);
    cout << "\nPreorder: ";
    bt.preorder(0);
    cout << "\nPostorder: ";
    bt.postorder(0);
    cout << endl;

    return 0;
}