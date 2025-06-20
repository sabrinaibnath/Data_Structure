#include<iostream>
using namespace std;
int Length(char s[]){
    int length=0;
    for(int i=0;s[i]!='\0';i++){
        length++;
    }
    return length;
}
int main(){
    char arr[100];

    cout<<"Please enter your string: "<<endl;
    cin.getline(arr,100);
    
    int ans=Length(arr);
   
    cout<<"the length of your string: "<<ans<<endl;
}