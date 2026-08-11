#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> directions = {{1, 1}, {0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};

    bool isSafe(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (m == 0 || n == 0 || grid[0][0] != 0 || grid[m-1][n-1] != 0)
            return -1;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        // set of (dist, (x, y)) -- same idea as (dist, node) in your template
        set<pair<int, pair<int,int>>> st;

        dist[0][0] = 1; // path length counts cells visited, so start cell = 1
        st.insert({1, {0, 0}});

        while (!st.empty()) {
            auto top = *st.begin();
            st.erase(st.begin());

            int d = top.first;
            int x = top.second.first;
            int y = top.second.second;

            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (isSafe(nx, ny, m, n) && grid[nx][ny] == 0) {
                    if (d + 1 < dist[nx][ny]) {
                        auto record = st.find({dist[nx][ny], {nx, ny}});
                        if (record != st.end())
                            st.erase(record);

                        dist[nx][ny] = d + 1;
                        st.insert({dist[nx][ny], {nx, ny}});
                    }
                }
            }
        }

        return dist[m-1][n-1] == INT_MAX ? -1 : dist[m-1][n-1];
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {{0,1},{1,0}};
    cout << "Test 1: " << sol.shortestPathBinaryMatrix(grid1) << " (expected 2)" << endl;

    vector<vector<int>> grid2 = {{0,0,0},{1,1,0},{1,1,0}};
    cout << "Test 2: " << sol.shortestPathBinaryMatrix(grid2) << " (expected 4)" << endl;

    vector<vector<int>> grid3 = {{1,0,0},{1,1,0},{1,1,0}};
    cout << "Test 3: " << sol.shortestPathBinaryMatrix(grid3) << " (expected -1)" << endl;

    return 0;
}