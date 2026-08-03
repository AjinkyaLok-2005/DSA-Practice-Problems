#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    void DFS(vector<vector<int>>& heights, int i, int j, int prevCellVal, vector<vector<bool>>& visited)
    {
        if(i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size())
        {
            return;
        }

        if(heights[i][j] < prevCellVal || visited[i][j])
            return;

        visited[i][j] = true;

        for(auto &dir : directions)
        {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            DFS(heights, i_, j_, heights[i][j], visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> result;

        vector<vector<bool>> pacificVisited(m, vector<bool>(n, false));
        vector<vector<bool>> atlanticVisited(m, vector<bool>(n, false));

        // Top row -> Pacific
        // Bottom row -> Atlantic
        for(int j = 0; j < n; j++)
        {
            DFS(heights, 0, j, INT_MIN, pacificVisited);
            DFS(heights, m - 1, j, INT_MIN, atlanticVisited);
        }

        // Left column -> Pacific
        // Right column -> Atlantic
        for(int i = 0; i < m; i++)
        {
            DFS(heights, i, 0, INT_MIN, pacificVisited);
            DFS(heights, i, n - 1, INT_MIN, atlanticVisited);
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(pacificVisited[i][j] && atlanticVisited[i][j])
                {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };

    Solution obj;
    vector<vector<int>> result = obj.pacificAtlantic(heights);

    cout << "Cells that can reach both Pacific and Atlantic Oceans:\n";

    for(auto &cell : result)
    {
        cout << "[" << cell[0] << ", " << cell[1] << "]" << endl;
    }

    return 0;
}