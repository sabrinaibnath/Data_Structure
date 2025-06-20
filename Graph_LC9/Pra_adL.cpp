#include<bits/stdc++.h>
using namespace std;
class Graph{
    map<int,list<int>>graph;

    public:
    void add_edges(int s,int d){
        graph[s].push_back(d);
        graph[d].push_back(s);
    }

    void print(){
        for(auto i:graph){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph g;
    int vertex, edge;
    cin>>vertex>>edge;
      for(int i=0;i<edge;i++){
        int h,w;
        cin>>h>>w;
        
        g.add_edges(h,w);
    }

    g.print();
    return 0;

}