#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    return a[2]<b[2];
}

void Make_Set(vector<int>&parent, vector<int>& rank,int n){
    for(int i=0;i<n;i++){
        parent[i]=i;//initially the parent of each node is themself
        rank[i]=0;//initially the rank of each mode is 0;
    }
}

int find_Parent(vector<int>& parent, int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node]=find_Parent(parent,parent[node]);//the logic of path compression

}

void unionSet(int u, int v, vector<int>& parent,vector<int>& rank){
    u=find_Parent(parent,u);
    v=find_Parent(parent,v);

    if(rank[u]<rank[v]){
        parent[u]=v;
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}

int Krushkal(vector<vector<int>>& graph,int n){
    sort(graph.begin(),graph.end(),cmp);

    vector<int>parent(n);
    vector<int>rank(n);
    Make_Set(parent,rank,n);
    
    int minimumWt=0;
    int size=graph.size();
    
    for(int i=0;i<size;i++){
        int u=find_Parent(parent,graph[i][0]);
        int v=find_Parent(parent,graph[i][1]);
        int wt=graph[i][2];

        if(u!=v){
            minimumWt+=wt;
            unionSet(u,v,parent,rank);
        }
    }

    return minimumWt;
}

int main()
{
    int n,edges;
    vector<vector<int>> graph;

    cout<<"please enter the number of nodes: ";
    cin>>n;

    cout<<endl<<"please enter the number of edges: ";
    cin>>edges;

    cout<<"please enter the edges with weight: ";
    for(int i=0;i<edges;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        graph.push_back({u,v,wt});
    }

    int result=Krushkal(graph,n);

    cout<<result<<endl;

    return 0;

}