#include<bits/stdc++.h>
using namespace std;

void DFS(int city,vector<vector<int>>& isc,vector<bool>& visited,int n)
{
    visited[city]=true;

    for(int j=0;j<n;j++){
        if(isc[city][j] == 1 && !visited[j]){
            DFS(j,isc,visited,n);
        }
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                DFS(i, isConnected, visited, n);
                provinces++;
            }
        }

        return provinces;
}

int main()
{
     vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    cout << "Total provinces: " <<findCircleNum(isConnected) << endl;
    return 0;
}

