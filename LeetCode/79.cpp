#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int m;
    int n;

    vector<vector<int>> dirs = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    bool dfs(vector<vector<char>>& board, string word, int i, int j, int l)
    {
        // Out of bounds
        if(i < 0 || i >= m || j < 0 || j >= n)
            return false;

        // Character doesn't match
        if(board[i][j] != word[l])
            return false;

        // Entire word found
        if(l == word.length() - 1)
            return true;

        // Mark current cell as visited
        char original = board[i][j];
        board[i][j] = '#';

        // Try all 4 directions
        for(auto& dir : dirs)
        {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if(dfs(board, word, ni, nj, l + 1))
                return true;
        }

        // Backtracking
        board[i][j] = original;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};


int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word = "ABCCED";

    Solution obj;

    bool result = obj.exist(board, word);

    if(result)
        cout << "Word exists in the board" << endl;
    else
        cout << "Word does not exist in the board" << endl;

    return 0;
}