#include<bits/stdc++.h>
using namespace std;

bool isPlanar(int edges,int vertex){
    if(edges<=(3*vertex -6)){
        return true;
    }
    else{
        return false;
    }
}
void addEdges(vector<vector<int>>&graph,int s,int d){
    graph[s].push_back(d);
    graph[d].push_back(s);
}
int main()
{
    int edges,vertex;

    cout<<"please enter the number of vertex: ";
    cin>>vertex;

    cout<<"please enter the number of edges: ";
    cin>>edges;

    vector<vector<int>> graph(vertex);

    for(int i=0;i<edges;i++){
        int s,d;
        cin>>s>>d;
        addEdges(graph,s,d);
    }

    cout<<isPlanar(edges,vertex);

    return 0;

}