#include<bits/stdc++.h>
using namespace std;
void Dfs_rec(vector<vector<int>>& graph,int s, vector<bool>& visited){
        visited[s]=true;
        cout<<s<<" ";

        for(auto u:graph[s]){
            if(visited[u]==false){
                Dfs_rec(graph,u,visited);
            }
        }
}

void DFS(vector<vector<int>>& graph,int s){

    vector<bool>visited(graph.size(),false);
       Dfs_rec(graph,s,visited);
}

void addEdge(vector<vector<int>> &graph,int s,int t){
    graph[s].push_back(t);
    graph[t].push_back(s);
}

int main()
{
    int n,m;
    cout<<"please enter the number of vertices: ";
    cin>>n;

    cout<<"please enter the number of edges: ";
    cin>>m;

    vector<vector<int>>graph(n);
    cout<<"please enter the edges: ";
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
      addEdge(graph,x,y);
    }

    int s;
    cin>>s;

    DFS(graph,s);

    return 0;
}