#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;//made adjancecy list global
vector<bool>vis;
vector<int>col;
bool bi;
void color(int u,int current){
    if(col[u]!=-1 && col[u]!=current){
            bi=false;
            return;
    }
    col[u]=current;
     
     if(vis[u]){
        return;
     }
     else{
        vis[u]=true;
     }

     for(auto i:adj[u]){
        color(i,current xor 1); 
     }
}
int main()
{
    int v,ed;
    cin>>v>>ed;
    bi=true;

    adj=vector<vector<int>>(v);
    vis=vector<bool>(v,false);
    col=vector<int>(v,-1);

    for(int i=0;i<ed;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i<v;i++){
      if(!vis[i]){
        color(i,0);
      }
    }
    if(bi){
        cout<<"bipartite";
    }
    else{
        cout<<"not";
    }
}