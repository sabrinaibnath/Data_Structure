#include<bits/stdc++.h>
using namespace std;
class Node{
  char node_name;

  public:
  Node(char c){
    node_name=c;
  }

  char getNode() const{
     return node_name;
  }

};
class Graph{
     vector<vector<int>> adj_matrix;
     vector<Node> nodes;

    public://constructor of graph class
    Graph(int n)
    {
        adj_matrix=vector<vector<int>>(n,vector<int>(n,0)); //vector<int>(n,0) is creating a row and vector<vector<int>>(n, this part is creating n rows
    }
    
    void addNode(Node node)
    {
       nodes.push_back(node);
    }


    void add_edge(int source ,int destination)
    {//this fucntion will add edges
       int c=adj_matrix.size();
    
       if (source >=c|| destination >=c || source < 0 || destination < 0 ) {
            cout << "Invalid edge! Vertex out of bounds.\n";
            return;
        }
       else{
       adj_matrix[source][destination]=1;//will only have edges if from x to y
     }
       
    }

    bool checkEdge(int source ,int destination)
    {
      if(adj_matrix[source][destination]==1){
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
        for( const Node& h:nodes){
            cout<<h.getNode() <<" ";
        }
        cout<<endl;

        int n=adj_matrix.size();
        for(int i=0;i<n;i++){
            cout<<nodes[i].getNode()<<" ";
            for(int j=0;j<n;j++){
                cout<<adj_matrix[i][j]<<" ";
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
        g.addNode(Node(labels[i]));
    }

    cout<<"enter the edges: "<<endl;
    for(int i=0;i<edges;i++){

        int x,y;
        cin>>x>>y;
        g.add_edge(x,y);
    }

    g.print();

    cout<<g.checkEdge(0,0);

    return 0;
}