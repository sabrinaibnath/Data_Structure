#include<bits/stdc++.h>
using namespace std;

bool isBipartite(int v,vector<vector<int>>&graph,int s){
    
    queue<int>q;
    q.push(s);//pushing the starting point into queue
    vector<int>color(v,-1);//created a vector with size v and all value is -1
    color[0]=0;//coloring initial node
    while(!q.empty()){
        int node=q.front();//taking the most first element in a variable
        q.pop();
         
         for(auto it: graph[node]){
            if(color[it]==-1){//if the adjacent node is not colored, u will give the opposite color
               color[it]=!color[node];
               q.push(it);
            }
            else if(color[it]==color[node]){//if the adjacent node has the same color
                  return false;
            }
         }
    }

    return true;
}

void addEdges(vector<vector<int>>& graph,int s,int d){
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

    vector<vector<int>> graph(v);

    cout<<"please enter the edges: ";
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        
        addEdges(graph,x,y);
    }

    int starting;
    cout<<"please enter the starting point; ";
    cin>>starting;
     
     bool r=isBipartite(v,graph,starting);
    cout<<(r? "true":"false");

    return 0;
}