#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i-1 >= 0)
                    grid[i][j] += grid[i-1][j];
                
                if(j-1 >= 0)
                    grid[i][j] += grid[i][j-1];
                
                if(i-1 >=0 && j-1 >= 0)
                    grid[i][j] -= grid[i-1][j-1];

                if(grid[i][j] <= k)
                    count++;
                else
                    break;
            }
        }
       
        return count;
    }
};

int main() {
    Solution obj;

    // Example grid
    vector<vector<int>> grid = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    int k = 4;

    int result = obj.countSubmatrices(grid, k);

    cout << "Count of submatrices with sum <= " << k << " is: " << result << endl;

    return 0;
}