#include<iostream>
using namespace std;


void SUBSTRING(char s[],int i,int l)
{
 for(int j=i;j<(l+i);j++){
       cout<<s[j];
      }
}
int main()
{
char arr[100];
cout<<"please enter your string: "<<endl;
cin.getline(arr,100);

int initial;
cout<<"Please enter the initial index of the subString: ";
cin>>initial;

int length;
cout<<"Please enter the length of the substring: ";
cin>>length;

SUBSTRING(arr,initial,length);


}