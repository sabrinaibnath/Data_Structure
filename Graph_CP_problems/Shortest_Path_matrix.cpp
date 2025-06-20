#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.size(), level = 0;
        vector<pair<int, int>> dir = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        while (!q.empty()) {
            int size = q.size();
            level++;

            while(size--) {
                auto cur = q.front();
                q.pop();
                int x = cur.first, y = cur.second;

                if(x == n - 1 and y == m - 1) return level;

                for(auto d : dir) {
                    int nx = x + d.first, ny = y + d.second;

                    if(nx < 0 or nx >= n or ny < 0 or ny >= m || grid[nx][ny] == 1) continue;

                    grid[nx][ny] = 1; // mark as visited
                    q.push({nx, ny});
                }
            }
        }

        return -1;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 1, 0},
        {1, 0, 1},
        {1, 1, 0}
    };

    Solution sol;
    int ans = sol.shortestPathBinaryMatrix(grid);
    cout << "Shortest path: " << ans << endl;

    return 0;
}
