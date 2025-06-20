#include <bits/stdc++.h>
using namespace std;


void minimumColors(int N,vector<int>& U, vector<int>& V)
{

     vector<vector<int>> adj(N);
    // Initialise colors array to 1
    // and count array to 0
    vector<int> count(N, 0);
    vector<int> colors(N, 1);

    // Create adjacency list of
    // a graph
    for (int i = 0; i < N; i++) {
        adj[V[i] - 1].push_back(U[i] - 1);
        count[U[i] - 1]++;
    }

    // Declare queue Q
    queue<int> Q;

    // Traverse count[] and insert
    // in Q if count[i] = 0;
    for (int i = 0; i < N; i++) {
        if (count[i] == 0) {
            Q.push(i);
        }
    }

    // Traverse queue and update
    // the count of colors
    // adjacent node
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        // Traverse node u
        for (auto x : adj[u]) {
            count[x]--;

            // If count[x] = 0
            // insert in Q
            if (count[x] == 0) {
                Q.push(x);
            }

            // If colors of child
            // node is less than
            // parent node, update
            // the count by 1
            if (colors[x] <= colors[u]) {
                colors[x] = 1 + colors[u];
            }
        }
    }

    // Stores the minimumColors
    // requires to color the graph.
    int minColor = -1;

    // Find the maximum of colors[]
    for (int i = 0; i < N; i++) {
        minColor = max(minColor, colors[i]);
    }

    // Print the minimum no. of
    // colors required.
    cout << minColor << endl;
}

// Driver function

int main() {
    int N, E;
    cin >> N >> E;

    vector<int> u(E);
    vector<int> v(E);

    cout << "enter the source vertex: ";
    for(int i = 0; i < E; i++) {
        cin >> u[i];
    }

    cout << "enter the destination vertex: ";
    for(int i = 0; i < E; i++) {
        cin >> v[i];
    }

    minimumColors(N,u,v);
    return 0;
}