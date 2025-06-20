#include<bits/stdc++.h>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size=0;

    void insert(int value){
        size=size+1;
        int index=size;
        arr[index]=value;

        while(index>1){
            int parent=index/2;

            if(arr[parent]< arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
   }

   void deleteFromHeap(){
    if(size==0){
        cout<<"Nothing to deltete ";
        return;
    }
    
    //deleting the root node(swapping with the most lower node)
    arr[1]=arr[size];
    size--;

    // take root node to it's correct position

    int i=1;
    while(i<size){
        int leftIndex=2*i;
        int rightIndex=2*i+1;

        if(leftIndex<size && arr[i]< arr[leftIndex]){
            swap(arr[i],arr[leftIndex]);
            i=leftIndex;
        }
        else if(rightIndex< size && arr[i]< arr[rightIndex]){
            swap(arr[i],arr[rightIndex]);
            i=rightIndex;
        }
        else{
            return;
        }
    }

   }

   void print()
   {
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
   }
};

int main()
{

    Heap h;
    int node;
    cout<<"please enter the number of nodes: ";
    cin>>node;

    for(int i=1;i<=node;i++){
        int x;
        cin>>x;
        h.insert(x);
    }

    h.print();

    cout<<"after deletion: ";
    h.deleteFromHeap();
    h.print();

    return 0;
}