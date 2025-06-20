#include <iostream>
#include <cstring>
using namespace std;

int Pattern_Matching(char P[], char T[], int R, int S) {
    int k=1;
    int Max=S-R+1;
    int Index=0;
    while(k<=Max){
        int L=0;
        for(L=0;L<R;L++){
            if(P[L]!=T[k+L-1]){
                break;
            }
        }
        if(L==R){
            Index=k;
            break;
        }
        k=k+1;
    }
        
   return Index;
}

int main() {
    // Input text and pattern
    char T[100], P[100];
    cout << "Enter the text: ";
    cin.getline(T, 100);
    cout << "Enter the pattern: ";
    cin.getline(P, 100);

    int S = strlen(T); // Length of text
    int R = strlen(P); // Length of pattern

    int result=Pattern_Matching(P, T, R, S);
    if(result==0){
        cout<<"pattern not found"<<endl;
    }
    else{
        cout<<"Pattern is found at index: "<<result<<endl;
    }

    
}
