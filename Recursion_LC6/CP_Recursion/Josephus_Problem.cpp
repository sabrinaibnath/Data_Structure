#include<bits/stdc++.h>
using namespace std;

int Josephus_Problem(int n,int k){
        if(n==1){
            return 0;
        }

       return (Josephus_Problem(n-1,k)+k )%n; //Recursive Step: Finds the survivor position for n-1 people.
                                         //Adding k: Accounts for the elimination shift.
                                         //Modulo n: Ensures circular indexing.

}
int main()
{
    int n,k;
    cin>>n>>k;

    cout<<Josephus_Problem(n,k)+1<<endl;
    return 0;
}