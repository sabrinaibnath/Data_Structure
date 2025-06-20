#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,int col,vector<int>&color,vector<int>graph[]){
       color[node]=col;

       for(auto it:graph[node] ){
        if(color[it]==-1){
            if(dfs(it,!col,color,graph)){
                return false;
            }
        }
        else if(color[it]==col){
             return false;
        }
       }
       return true;
}

bool isBipartite(int v, vector<int>graph[]){//here the graph is in adjancecy list mood
      
      vector<int>color(v,-1);
      for(int i=0;i<v;i++){
        if(color[i]==-1){
            if(dfs(i,0,color,graph)==false){
                return false;
            }
        }
      }
       return true;
}

void addEdges(vector<int>graph[],int s,int d){
    graph[s].push_back(d);
    graph[d].push_back(s);
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

   
     
     bool r=isBipartite(v,graph);
    cout<<(r? "true":"false");

    return 0;
}