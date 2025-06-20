#include<bits/stdc++.h>
using namespace std;

class Graph{
    map<int,list<int>> adjList;

    public:
    void add_edge(int u,int v){

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void print()
    {
        cout<<"Adjancency list for the graph: "<<endl;
        for(auto i: adjList){
            cout<<i.first<<"-> ";
            for(auto j: i.second){
                cout<< j <<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g;
    int n,ed;
    cout<<"enter the number of vertices: ";
    cin>>n;
    cout<<"enter the number of edges: ";
    cin>>ed;

    for(int i=0;i<ed;i++){
        int h,w;
        cin>>h>>w;
        
        g.add_edge(h,w);
    }

    g.print();
    return 0;
}
