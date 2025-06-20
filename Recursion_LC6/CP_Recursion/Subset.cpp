#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int>path;
        backtrack(nums,0,path,result);
        return result;
        
    }

    void backtrack(vector<int>& nums,int start,vector<int>& path,vector<vector<int>>& result){
    result.push_back(path);
    int s=nums.size();
    for(int i=start;i<s;i++){
        path.push_back(nums[i]);
        backtrack(nums,i+1,path,result);
        path.pop_back();
    }
}

};

int main() {
    // Input the array size
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Input the array elements
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Create an object of Solution class and get the subsets
    Solution solution;
    vector<vector<int>> result = solution.subsets(nums);

    // Print all the subsets
    cout << "Subsets of the given array are: " << endl;
    for (const auto& subset : result) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i != subset.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
