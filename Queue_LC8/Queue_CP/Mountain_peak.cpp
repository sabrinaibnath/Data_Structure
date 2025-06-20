#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);

    // Input the heights
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    // Vector to store the next greater element for each index
    vector<int> result(n);

    // Brute force approach to find the next greater element
    for (int i = 0; i < n; i++) {
        result[i] = -1;  // Assume no greater element
        for (int j = i + 1; j < n; j++) {
            if (heights[j] > heights[i]) {
                result[i] = heights[j];  // Found the next greater element
                break;  // Exit the inner loop as we found the next greater element
            }
        }
    }

    // Output the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
