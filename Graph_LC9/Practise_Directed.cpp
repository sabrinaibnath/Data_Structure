#include<bits/stdc++.h>
using namespace std;
class Node{
    char node_name;

    public:
    Node(char c){
        node_name=c;
    }

    char get_node()const{
        return node_name;
    }
};

class Graph{
    vector<vector<int>>graph;
    vector<Node>labels;

    public:
    Graph(int v){
        graph=vector<vector<int>>(v,vector<int>(v,0));
    }

    void Add_node(Node node){
        labels.push_back(node);
    }

    void Add_edges(int sc,int d){
        graph[sc][d]=1;
    }

    bool check_edge(int s,int d){
        if(graph[s][d]==1){
            return true;
        }
        else{
            return false;
        }
    }

   void print()
    { 

      cout<<"ADjacency Matrix for the Graph: "<<endl;
         cout<<"  ";  
        for( const Node& h:labels){
            cout<<h.get_node()<<" ";
        }
        cout<<endl;

        int n=graph.size();
        for(int i=0;i<n;i++){
            cout<<labels[i].get_node()<<" ";
            for(int j=0;j<n;j++){
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n,edges;
    cout<<"please enter the number of vertix: "<<endl;
    cin>>n;
    
    cout<<"please enter the number of edges: "<<endl;
    cin>>edges;


    Graph g(n);
    
    vector<char> labels(n);//store node labels
    
    cout<<"enter the nodes: "<<endl;
    for(int i=0;i<n;i++){
        cin>>labels[i];
        g.Add_node(Node(labels[i]));
    }

    cout<<"enter the edges: "<<endl;
    for(int i=0;i<edges;i++){

        int x,y;
        cin>>x>>y;
        g.Add_edges(x,y);
    }

    g.print();

    cout<<g.check_edge(0,0);

    return 0;
}