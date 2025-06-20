#include<iostream>
#include<string.h>
using namespace std;

int LCS(char str1[], char str2[], int n, int m) {
    int L[n + 1][m + 1]; // Declared a 2D 

    // Initialized the first column
    for (int i = 0; i <= n; i++) {
        L[i][0] = 0;
    }

    // Initialized the first row
    for (int j = 0; j <= m; j++) {
        L[0][j] = 0;
    }

    // Fill the L array 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1; //  matching Characters
            } else {
                L[i][j] = max(L[i][j - 1], L[i - 1][j]); // Characters don't match
            }
        }
    }

    // Returning the length of the Longest Common Subsequence
    return L[n][m];
}

int main() {
    char str1[100], str2[100];
    
    cout << "Enter first string: ";
    cin.getline(str1, 100);
    cout << "Enter second string: ";
    cin.getline(str2, 100);

    int n = 0, m = 0;

    // Calculate the length of both strings
    while (str1[n] != '\0') {
        n++;
    }

    while (str2[m] != '\0') {
        m++;
    }

    // Call the LCS function
    int result = LCS(str1, str2, n, m);

    // Output the result
    cout << "Result is: " << result << endl;

    return 0;
}
