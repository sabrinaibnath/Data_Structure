#include <iostream>
using namespace std;

int LENGTH(char a[]){
     int s=0;
     while(a[s]!='\0'){
        s++;
     }
     return s;
}
char* Substring(char b[],int ini,int l){
   char* ns=new char[l+1];
   int k=0;
   for(int i=ini;i<l+ini;i++){
      ns[k]=b[i];
      k++;
   }
   ns[k]='\0';
   return ns;
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
    for (int i = length1; i >=position; i--) {
        arr[i + length2] = arr[i];
    }
    //in this part we are doing insertion
    for (int i = 0; i < length2; i++) {
        arr[position + i] = arr2[i];
    }
    return arr;
}
char* Delete(char s[], int pos, int len) {
    int length = 0, i = 0;

    //here we are Calculating the length of the string
    while (s[i] != '\0') {
        length++;
        i++;
    }
    //here we are checking Validate position and length
    if (pos < 0 || pos >= length || len < 0 || pos + len > length) {
        cout << "Invalid position or length!" << endl;
    }
    //here we are Shift characters to delete the specified portion
    for (int j = pos; j <= length; j++) {
        s[j] = s[j + len];
    }

    return s;
}
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
int Index(char a[], char b[]) {
    int l1 = 0, l2 = 0;

    // Calculate the length of both strings
    while (a[l1] != '\0') {
        l1++;
    }
    while (b[l2] != '\0') {
        l2++;
    }

    // Iterate through `a` and check if `b` exists as a substring
    for (int i = 0; i <= l1 - l2; i++) {
        int j = 0;

        // Compare substring of `a` with `b`
        while (j < l2 && a[i + j] == b[j]) {
            j++;
        }

        // If full substring matches, return index
        if (j == l2) {
            return i+1;
        }
    }
    
    return -1; // If not found, return -1
}
int main()
{
   cout<<"please enter your string:";
   char arr[50];
   cin.getline(arr,50);

   char so[50];
   cout<<"please enter the string u want to insert: ";
   cin.getline(so,50);

   cout<<"please enter your string to delete:";
   char Dar[50];
   cin.getline(Dar,50);

   char str[50];
   cout<<"please enter your string for replacement: ";
   cin.getline(str,50);

   char p[50];
   cout<<"please enter the string u want to replace: ";
   cin.getline(p,50);

   char r[50];
   cout<<"please enter the replacement: ";
   cin.getline(r,50);

   char str1[50];
   cout<<"please enter your first string to concat: ";
   cin.getline(str1,50);

   char str2[20];
   cout<<"please enter your second string to concat: ";
   cin.getline(str2,20);

   char arr[100];
    cout << "Please enter your string for indexing: ";
    cin.getline(arr, 100);


    char pattern[50];
    cout << "Please enter the substring you are looking for: ";
    cin.getline(pattern, 50);

   int size=LENGTH(arr);
   cout<<"Length of your string is: "<<size<<endl;

   int initial,sublength;
   cout<<"Enter your initial position: ";
   cin>>initial;
   cout<<"Enter the length of the sunstring: ";
   cin>>sublength;
   char* sub = Substring(arr, initial, sublength);
   cout<<"SubString is: "<<sub<<endl;

   int position;
   cout<<"please enter the position: ";
   cin>>position;
   char* re=INSERT(arr,position,so);
   cout<<"the String after modification: "<<re<<endl;

   int Dlength,Dposition;
   cout<<"please enter the position for deletion: ";
   cin>>Dposition;
   cout<<"please enter the length for deletion: ";
   cin>>Dlength;
   char* result =Delete(Dar,Dposition,Dlength);
   cout<<"After Deletion the String: "<<result<<endl;
   
   char* po=REPLACEMENT(str,p,r);
   cout<<"After replacement "<<po;


   char* u=ConCat(str1,str2);
   cout<<"After concatination:"<<u<<endl;

   int r = Index(arr, pattern);

    cout<<"the index is:"<<r;
}