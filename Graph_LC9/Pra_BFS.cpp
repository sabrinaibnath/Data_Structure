#include<bits/stdc++.h>
using namespace std;
void BFS(vector<vector<int>>graph, int s){
    queue<int>q;

    vector<int>visited(graph.size(),false);

    visited[s]=true;
    q.push(s);

    while(!q.empty()){
        int current=q.front();
        q.pop();
        cout<<current<<" ";

        for(int x:graph[current]){
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
            }
        }

    }
}
void add_edges(vector<vector<int>>& g,int s,int d){
    g[s].push_back(d);
    g[d].push_back(s);
}
int main()
{
     int n,m;
    cout<<"enter the number of vertices: "<<endl;
    cin>>n;

    cout<<"enter the number of edges: "<<endl;
    cin>>m;

    vector<vector<int>> gr(n);

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        add_edges(gr,x,y);
    } 

    int s;
    cout<<"please enter the starting point: ";
    cin>>s;

    cout<<"BFS starting : "<<endl;
    BFS(gr,s);
}