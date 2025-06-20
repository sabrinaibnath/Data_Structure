#include<iostream>
using namespace std;
char* ConCat(char s1[],char s2[]){
    int length=0,j=0;
    while(s1[length]!='\0'){
        length++;
    }

    while(s2[j]!='\0'){
        s1[length+j]=s2[j];
        j++;
    }
    s1[j+length]='\0';
    return s1;
}
int main()
{
    char str1[50];
    char str2[20];

    cout<<"please enter your first string: ";
    cin.getline(str1,50);

    cout<<"please enter your second string: ";
    cin.getline(str2,20);

    char* u=ConCat(str1,str2);
    cout<<u;

}