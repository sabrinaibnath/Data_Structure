#include<iostream>
using namespace std;

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
    char arr[100];
    cout << "Please enter your string: ";
    cin.getline(arr, 100);

    char pattern[50];
    cout << "Please enter the substring you are looking for: ";
    cin.getline(pattern, 50);

    int r = Index(arr, pattern);

    cout<<r;
}