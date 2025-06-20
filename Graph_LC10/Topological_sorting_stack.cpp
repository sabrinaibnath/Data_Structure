#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>& visited,stack<int>&st,vector<int>graph[]){
    visited[node]=1;
    for(auto it:graph[node]){
        if(!visited[it]){
            dfs(it,visited,st,graph);
        }
    }
     st.push(node);
}
vector<int> Topological_sorting(int v,vector<int>graph[]){
    vector<int> visited(v,0);

    stack<int>st;

    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,visited,st,graph);
        }
    }

    vector<int>result;
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }

    return result;
}

void addEdges(vector<int>graph[],int s,int d){
    graph[s].push_back(d);
   
}

int main()
{
    int v,e;
    cout<<"please enter the vertex: ";
    cin>>v;

    cout<<"please enter the edges: ";
    cin>>e;

    vector<int> graph[v];

    cout<<"please enter the edges: ";
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        
        addEdges(graph,x,y);
    }

    vector<int>result;
    result=Topological_sorting(v,graph);

   for(int i=0;i<v;i++){
    cout<<result[i]<<" ";
   }
    return 0;
}