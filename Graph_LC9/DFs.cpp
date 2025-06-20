#include<bits/stdc++.h>
using namespace std;

void dfsRec(vector<vector<int>> &adj, vector<bool>&visited, int s)
{
    visited[s]=true;
    cout<<s<<" ";

    for(int i:adj[s]){
        if(visited[i]==false){
            dfsRec(adj,visited,i);
        }
    }
}

void DFS(vector<vector<int>> & adj,int s){
    vector<bool>visited(adj.size(),false);
    dfsRec(adj,visited,s);
}

void addEdge(vector<vector<int>> &adj,int s,int t){
    adj[s].push_back(t);
    adj[t].push_back(s);
}

int main()
{
    int n,m;
    cout<<"enter the number of vertices: "<<endl;
    cin>>n;

    cout<<"enter the number of edges: "<<endl;
    cin>>m;

    vector<vector<int>> adj(n);

    cout<<"enter the edges: ";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        addEdge(adj,u,v);
    }

    int s;
    cout<<"enter the source: ";
    cin>>s;

    cout<<"DFS traversal "<<endl;
    DFS(adj,s);

    return 0;
}