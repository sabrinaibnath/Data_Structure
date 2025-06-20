#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout<<"please enter ur string: ";
    getline(cin,s);

    map<string,int>m;
    
    stringstream ss(s);
    string w;

    while(ss >> w){
        m[w]++;
    }
    
    int max=0;
    string maxc="";

   for( auto it=m.begin(); it!= m.end();it++){
    if(it->second > max){
        max=it->second;
        maxc=it->first;
    }
   }

   cout<<"the mose frequent character is: "<<maxc<<" "<<max;

   return 0;
}