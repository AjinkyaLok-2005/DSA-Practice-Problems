#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int startRow = x;
        int endRow = x+k-1;

        int startCol = y;
        int endCol = y+k-1;

        for(int i = startRow; i <= endRow; i++)
        {
            for(int j = startCol; j <= endCol; j++)
            {
                swap(grid[i][j], grid[endRow][j]);
            }
            endRow--;
        }

        return grid;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,16}
    };

    int x = 1; // starting row
    int y = 1; // starting column
    int k = 2; // size of submatrix

    Solution obj;
    vector<vector<int>> result = obj.reverseSubmatrix(grid, x, y, k);

    cout << "Updated Grid:\n";
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}