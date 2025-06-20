#include<bits/stdc++.h>
using namespace std;

int spanningTree(int v, vector<vector<pair<int,int>>>adj){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    vector<int>visited(v,0);

    q.push({0,0});//just keeping wt and node
    int sum=0;
    while(!q.empty()){
        pair<int, int> it = q.top();
        q.pop();
        int node=it.second;
        int wt=it.first;

        if(visited[node]==1){
            continue;
        }
        else{
            visited[node]=1;
            sum+=wt;
        }

        for(auto it:adj[node]){
            int adjnode=it.first;
            int wt=it.second;

            if(!visited[adjnode]){
                q.push({wt,adjnode});
            }
        }
    }

    return sum;
}

int main()
{
    int v,e;
    cin>>v>>e;

     vector<vector<pair<int, int>>> adj(V); // adjacency list

     for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;

        adj[u].push_back({})
     }
}
