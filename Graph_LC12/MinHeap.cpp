#include<bits/stdc++.h>
using namespace std;

class MinHeap{
private:
    vector<int> heap;

    void heapifyUp(int index){
        if(index == 0) return;
        int parent = (index - 1) / 2;

        if(heap[index] < heap[parent]){
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index){
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;
         int s=heap.size();
        if(left < s && heap[left] < heap[smallest]){
            smallest = left;
        }

        if(right < s && heap[right] < heap[smallest]){
            smallest = right;
        }

        if(smallest != index){
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(int value){
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void removeMin(){
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int getMin(){
        if(heap.empty()){
            cout << "Heap is empty." << endl;
            return -1;
        }
        return heap[0];
    }

    void printHeap(){
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main(){

    MinHeap h;

    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(40);

    cout << "Min Heap: ";
    h.printHeap();

    cout << "Minimum: " << h.getMin() << endl;

    h.removeMin();
    cout << "Heap after removing min: ";
    h.printHeap();
    return 0;
}