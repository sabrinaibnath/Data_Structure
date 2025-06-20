#include<bits/stdc++.h>
using namespace std;
void TowerHanoi(int n,int scr,int helper,int des,vector<pair<int,int>>& moves){
    if(n==1){
        moves.push_back({scr,des});//moving the largest stack
        return; 
    }
    TowerHanoi(n-1,scr,des,helper,moves);//moving n-1 stack from source to helper with the help of destination
    moves.push_back({scr,des});
    cout<<"Transfer dis "<<n<<" from "<<scr<<" to "<<des<<endl;
    TowerHanoi(n-1,helper,scr,des,moves);//moving n-1 stack helper to destination with the help of source

}
int main()
{
    int n;
    cin>>n;
    
    vector<pair<int,int>> moves;
    TowerHanoi(n,1,2,3,moves);

    cout<<moves.size()<<endl;

    for(auto move:moves){
        cout<<move.first<< " "<<move.second<<endl;
    }
    return 0;
    
}