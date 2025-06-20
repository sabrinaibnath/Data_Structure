#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
     queue<int>q;
    for(int i=0;i<n;i++){
        int y;
        cin>>y;

       

        if(y==1){
            int c;
            cin>>c;
            q.push(c);
        }
        if(y==2){
            if(!q.empty()){
              q.pop();
            }
        }
        if(y==3){
            if(!q.empty()){
            cout<<q.front();

            }
            else{
                cout<<"Empty!"<<endl;
            }
        }
    }
    return 0;
}