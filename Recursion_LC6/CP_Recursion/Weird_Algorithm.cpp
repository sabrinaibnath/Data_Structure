#include<bits/stdc++.h>
using namespace std;
void algo(int n){

    cout<<n<<" ";

    if(n==1){
        return;
    }
    if(n%2==0){
       algo(n/2);
    }
    else{
       algo(3*n +1);
    }
}
int main(){
    int n;
    cin>>n;
    
    algo(n);

    cout<<endl;
    return 0;

}