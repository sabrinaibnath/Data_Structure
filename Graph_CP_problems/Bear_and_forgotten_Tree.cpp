#include<bits/stdc++.h>
using namespace std;

void addEdges(vector<vector<int>>& graph,);
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
     
    vector<vector<int>graph;
    vector<pair<int,int>>notC;

    for(int i=1;i<=m;i++){
        int s,d;
        cin>>s>>d;
        notC.push_back(make_pair(s,d));
    }
}