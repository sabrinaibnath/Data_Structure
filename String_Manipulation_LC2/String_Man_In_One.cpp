#include<iostream>
using namespace std;

void INDEX(char s[],char p[]){
    for(int i=0;i<'\0';i++){
        if(s[i]==p[i]){
            cout<<i;
        }
    }
}
void SUBSTRING(char s[],int i,int l)
{
 for(int j=i;j<(l+i);j++){
       cout<<s[j];
      }
}
char* INSERT(char arr[],int position,char arr2[])
{
  int length1=0,i=0,j=0,length2=0;
    while(arr[i]!='\0'){
        i++;
        length1++;
    }
    //cout<<length1<<endl;

    while(arr2[j]!='\0'){
        j++;
        length2++;
    }
    //cout<<length2<<endl;

    //here we are shifting so that we can insert, suppose str1=ABCDEF at 3 we want XYZ, if we insert XYZ after ABC the total length will be 
    //length1+length2(i+length1) and at that place we are shifting F,then at(length1+length2)-1 we are keeping E
    for (int i = length1; i >= position; i--) {
        arr[i + length2] = arr[i];
    }
    //in this part we are doing insertion
    for (int i = 0; i < length2; i++) {
        arr[position + i] = arr2[i];
    }
    return arr;
}
int main()
{
char arr[50];
cout<<"please enter your string: ";
cin.getline(arr,50);

char pattern[20];
cout<<"please enter the pattern you are looking for: ";
cin.getline(pattern,20);

//void INDEX(char s[],char p[]);

char arr2[20];
cout<<"Please enter your string: ";
    cin.getline(arr2,20);

    int position;
    cout<<"Please enter the position: ";
    cin>>position;

   char* result= INSERT(arr,position,arr2);

   cout<<result;
}