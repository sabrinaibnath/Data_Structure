#include<bits/stdc++.h>
using namespace std;

void reverse(queue<int>& q){
    if(q.empty()){
        return;
    }

    int fo=q.front();
    q.pop();

    reverse(q);

    q.push(fo);


}

#include <iostream>
#include <queue>
using namespace std;

// Function to reverse the queue using recursion
void reverseQueue(queue<int>& q) {
    // Base case: if the queue is empty, return
    if (q.empty()) {
        return;
    }

    // Step 1: Dequeue the front element
    int frontElement = q.front();
    q.pop();

    // Step 2: Recursively reverse the remaining queue
    reverseQueue(q);

    // Step 3: Re-enqueue the front element to the rear of the queue
    q.push(frontElement);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        queue<int> q;

        // Enqueue elements to the queue
        for (int i = 0; i < N; ++i) {
            int element;
            cin >> element;
            q.push(element);
        }

        // Reverse the queue
        reverseQueue(q);

        // Print the reversed queue
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }

    return 0;
}
