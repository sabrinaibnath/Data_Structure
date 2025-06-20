#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,count=0;
    cin>>n>>m;
    vector<vector<int>> aj(n);
    vector<int>ind(n,0);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        aj[u].push_back(v);
         ind[v]++;   
    }

    queue<int>q;
    for(int i=0;i<n;i++){
       if(ind[i]==0){
        q.push(i);
       }
    }
    vector<int> topo_order;

        while (!q.empty()) {
        int x = q.front();
        q.pop();
        topo_order.push_back(x);
        count++;

        for (auto i : aj[x]) {
            ind[i]--;
            if (ind[i] == 0) {
                q.push(i);
            }
        }
    }

    // If count is not equal to n, it means there's a cycle
    if (count != n) {
        cout << "\nCycle detected! Topological sort not possible.\n";
    } else {
        // Print topological order
        cout << "Topological Order: ";
        for (int node : topo_order) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
