#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m-k+1, vector<int>(n-k+1));

        for(int i = 0; i <= m-k; i++)
        {
            for(int j = 0; j <= n-k; j++)
            {
                set<int> val;

                for(int r = i; r <= i + k - 1; r++)
                {
                    for(int c = j; c <= j + k - 1; c++)
                    {
                        val.insert(grid[r][c]);
                    }
                }

                if(val.size() == 1)
                {
                    result[i][j] = 0;
                    continue;
                }

                int minAbsDiff = INT_MAX;
                auto prev = val.begin();
                auto curr = next(prev);

                while(curr != val.end())
                {
                    minAbsDiff = min(minAbsDiff, *curr - *prev);
                    prev = curr;
                    curr++;
                }

                result[i][j] = minAbsDiff;
            }
        }
        return result;
    }
};

int main() {
    int m, n, k;
    cout << "Enter rows, columns and k: ";
    cin >> m >> n >> k;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter grid values:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    vector<vector<int>> ans = obj.minAbsDiff(grid, k);

    cout << "\nResult:\n";
    for(auto &row : ans) {
        for(auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}