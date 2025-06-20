#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& adj, int s)
{
    queue<int>q;//create a queue for bfs
    
    // Initially mark all the vertices as not visited
    // When we push a vertex into the q, we mark it as 
    // visited
    vector<bool> visited(adj.size(), false);

    visited[s]=true;
    q.push(s);

    while(!q.empty())
    {
        int current=q.front();
        q.pop();
        cout<<current<<" ";

        for(int x:adj[current]){
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
            }
        }
    }
}
void addEdge(vector<vector<int>>& adj,
                          int u, int v) 
{
    adj[u].push_back(v);
    adj[v].push_back(u); // Undirected Graph
}
int main()
{
    int n,m;
    cout<<"enter the number of vertices: "<<endl;
    cin>>n;

    cout<<"enter the number of edges: "<<endl;
    cin>>m;

    vector<vector<int>> adj(n);

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        addEdge(adj,x,y);
    } 

    int s;
    cout<<"please enter the starting point: ";
    cin>>s;

    cout<<"BFS starting : "<<endl;
    bfs(adj,s);
}