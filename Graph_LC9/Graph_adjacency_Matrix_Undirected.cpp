#include<bits/stdc++.h>
using namespace std;

class Graph{
     vector<vector<int>> adj_matrix;
    
    public://constructor of graph class
    Graph(int n){
        adj_matrix=vector<vector<int>>(n,vector<int>(n,0)); //vector<int>(n,0) is creating a row and vector<vector<int>>(n, this part is creating n rows
    }

    void add_edge(int x,int y){//this fucntion will add edges
    int c=adj_matrix.size();
    
     if (x >=c|| y >=c) {
            cout << "Invalid edge! Vertex out of bounds.\n";
            return;
        }

        adj_matrix[x][y]=1;
        adj_matrix[y][x]=1;//for undirected graph
    }

    void print()
    {
        cout<<"ADjacency Matrix for the Graph: "<<endl;
        int n=adj_matrix.size();
        for(int i=0;i<n;i++){
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

    for(int i=0;i<edges;i++){
        int x,y;

        cin>>x>>y;
        g.add_edge(x,y);
    }

    g.print();

    return 0;
}