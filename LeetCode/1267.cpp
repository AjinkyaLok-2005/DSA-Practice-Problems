
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> indexColCount(n, 0);
        vector<int> indexRowCount(m, 0);

        // Count servers in each row and column
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    indexRowCount[i]++;
                    indexColCount[j]++;
                }
            }
        }

        int count = 0;

        // Count communicating servers
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1 &&
                   (indexColCount[j] > 1 || indexRowCount[i] > 1))
                {
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };

    Solution obj;

    int ans = obj.countServers(grid);

    cout << "Number of communicating servers: " << ans << endl;

    return 0;
}
