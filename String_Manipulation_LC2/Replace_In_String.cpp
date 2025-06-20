#include<iostream>
using namespace std;

char* REPLACEMENT(char a[],char p1[],char p2[]){
    int l=0;
    while(a[l]!='\0'){
        l++;
    }
    int l1=0;
     while(a[l1]!='\0'){
        l1++;
    }

    for(int i=0;i<l;i++){
        for(int j=0;j<l1;j++){
            if(a[i]==p1[j]){
                a[i]=p2[j];
            }
        }
    }
    return a;
}
int main()
{
    char str[50];
    cout<<"please enter your string: ";
    cin.getline(str,50);

    char p[50];
    cout<<"please enter the string u want to replace: ";
    cin.getline(p,50);

    char r[50];
    cout<<"please enter the replacement: ";
    cin.getline(r,50);

    char* re=REPLACEMENT(str,p,r);
    cout<<re;
}