#include<bits/stdc++.h>
using namespace std;

class Node{ // this class is used to make the labels, uk the A,B,C 
    char node_name;

    public:
    Node(char n){
        node_name=n;
    }

    char get_Node()const{ // as node_name is private that's why i need it to access the data
        return node_name;
    }
};

class Graph{
    vector<vector<int>> graph;
    vector<Node>labels;//it will contain the object of nodes

    public:
    Graph(int v)
    {
        graph=vector<vector<int>>(v,vector<int>(v,0));
    }

    void Add_Node(Node node){
        labels.push_back(node);
    }

    void Add_adges(int sc,int de){
        graph[sc][de]=1;
        graph[de][sc]=1;
    }

    bool check_edge(int s,int d){
        if(graph[s][d]==1){
            return true;
        }
        else{
            return false;
        }
    }

    void print(){
        int s=graph.size();

        cout<<"ADjacency Matrix for the Graph: "<<endl;
        cout<<"  ";  
        for( const Node& h:labels){
            cout<<h.get_Node() <<" ";
        }
        cout<<endl;

        for(int i=0;i<s;i++){
            //cout<<labels[i].get_Node()<<" ";
            for(int j=0;j<s;j++){
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};
int main()
{
    int n,m;

    cout<<"please enter the number of vertics: ";
    cin>>n;

    cout<<"please enter the number of edges: ";
    cin>>m;

    vector<char>nodes(n);

    Graph g(n);
    cout<<"please enter the nodes: ";
    for(int i=0;i<n;i++){
        cin>>nodes[i];
        g.Add_Node(Node(nodes[i]));
    }

    cout<<"please enter the edges: ";
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g.Add_adges(x,y);
    }

    g.print();

    return 0;


}