#include<bits/stdc++.h>
using namespace std;

int main()
{
    //creation 
    unordered_map<string,int>m;

    //insertion
    pair<string,int> p=make_pair("sabrina",72);
    m.insert(p);

    //another
    pair<string,int> q("ibnath",23);
    m.insert(q);
    
    //another
    m["nowshed"]=24;

    //search
    cout<<m["nowshed"]<<endl;
    cout<<m.at("sabrina")<<endl;
    //cout<<m.at("noki");
    cout<<m["noki"]<<endl;;//make a key where a it's value is 0

    //size
    cout<<m.size();

    //to check present
    cout<<m.count("bro")<<endl;//is there is not a key then will give zero

    //erase
    m.erase("nowsed");

    //taverse
    // for(auto i:m){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    
    //iterator
    unordered_map<string,int> ::iterator it=m.begin();

    while(it !=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }


}