#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int num;
    vector<int> vec;

    while (cin >> num) {
        vec.push_back(num);
        sort(vec.begin(), vec.end());

        int n = vec.size();
        if (n % 2 == 1) {
            cout << vec[n / 2] << endl;
        } else {
            cout << (vec[n / 2 - 1] + vec[n / 2]) / 2 << endl;
        }
    }

    return 0;
}