#include<bits/stdc++.h>
using namespace std;


void minimumC(vector<int>& u,vector<int>& v,int e,int vr){
    
    vector<int>color(vr,1);
    vector<int>count(vr,0);

    vector<vector<int>> adj(vr);

    for(int i=0;i<e;i++){
        adj[v[i]-1].push_back(u[i]-1);
        count[u[i]-1]++;
    }

    queue<int>q;

    for(int i=0;i<vr;i++){
        if(count[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto x: adj[node]){
            count[x]--;

            if(count[x]==0){
                q.push(x);
            }

            if(color[x]<=color[node]){
                color[x]=1+color[node];
            }
        }
    }

    int ans=*max_element(color.begin(),color.end());

    cout<<ans<<endl;

}
int main() {
    int vr, e;
    cin >> vr >> e;

    vector<int> u(e);
    vector<int> v(e);

    cout << "enter the source vertex: ";
    for(int i = 0; i < e; i++) {
        cin >> u[i];
    }

    cout << "enter the destination vertex: ";
    for(int i = 0; i < e; i++) {
        cin >> v[i];
    }

    minimumC(u, v, e, vr);
    return 0;
}
