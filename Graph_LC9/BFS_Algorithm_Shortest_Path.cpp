#include <bits/stdc++.h>
using namespace std;

int main(){
    int u, v, n, e;
    cin >> n >> e;
    vector<int> adj[n + 1];

    for (int i = 0; i < e; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    for (int i = 1; i <= n; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    vector<int> vis(n + 1, 0);
    vector<int> level(n + 1, 0);
    vector<int> parent(n + 1, -1);
    queue<int> q;

    int src = 1;
    vis[src] = 1;
    level[src] = 0;
    q.push(src);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : adj[u]){
            if(vis[v]){ 
                continue;
            }
            level[v] = level[u] + 1;
            vis[v] = 1;
            parent[v] = u;     // Save parent of v
            q.push(v);
        } 
    }

    /////////////////////////////////////////////////
    cout << "Shortest paths from node " << src << ":\n";
    for(int i = 1; i <= n; i++){
        if(i == src){
            cout << "Node " << i << ": " << i << "\n";
            continue;
        }

        if(!vis[i]){
            cout << "Node " << i << ": Not reachable\n";
            continue;
        }

        // Reconstruct path
        vector<int> path;
        int cur = i;
        while(cur != -1){
            path.push_back(cur);
            cur = parent[cur];
        }
        reverse(path.begin(), path.end());

        cout << "Node " << i << ": ";
        for(int x : path) cout << x << " ";
        cout << "\n";
    }

    return 0;
}