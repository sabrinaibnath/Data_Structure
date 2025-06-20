#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>> adj[],int u,int v,int wt){
      adj[u].push_back(make_pair(v,wt));
      adj[v].push_back(make_pair(u,wt));
}

void shortestPath(vector<pair<int,int>> adj[],int v,int scr)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    
    vector<int> dist(v, INT_MAX);

    pq.push(make_pair(0,scr));
    dist[scr]=0;

   while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for(auto x:adj[u]){
            int v=x.first;
            int weight=x.second;
        if(dist[v]>dist[u]+weight){
            dist[v]=dist[u]+weight;
            pq.push(make_pair(dist[v],v));
        }
        }
     }
     cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < v; i++) {
        cout << i << "\t" << dist[i] << endl;
     }
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<pair<int, int>> adj[v];

    for (int i = 0; i < e; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        addEdge(adj, u, v, wt);
    }

    int src;  
    cout<<"enter the source: ";
    cin>>src;
    shortestPath(adj, v, src);

    return 0;
}