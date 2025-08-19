#include <bits/stdc++.h> 
using namespace std;

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    vector<int> temp;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)   // fixed condition
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row, y = col;

    // check same row (left side)
    while(y >= 0)
    {
        if(board[x][y] == 1) return false;
        y--;
    }

    x = row; y = col;
    // check upper-left diagonal
    while(x >= 0 && y >= 0)
    {
        if(board[x][y] == 1) return false;
        x--; y--;
    }

    x = row; y = col;
    // check lower-left diagonal
    while(x < n && y >= 0)
    {
        if(board[x][y] == 1) return false;
        x++; y--;
    }

    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    // base case
    if(col == n)
    {
        addSolution(ans, board, n);   // fixed ; 
        return;
    }

    for(int row = 0; row < n; row++)
    {
        if(isSafe(row, col, board, n))
        {
            // place queen
            board[row][col] = 1;
            solve(col+1, ans, board, n);
            // backtrack
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, board, n);
    return ans;
}

int main()
{
    int n;
    cout << "Enter number of queens (N): ";
    cin >> n;

    vector<vector<int>> solutions = nQueens(n);

    cout << "\nTotal Solutions: " << solutions.size() << "\n\n";

    int solCount = 1;
    for(auto &sol : solutions)
    {
        cout << "Solution " << solCount++ << ":\n";
        for(int i = 0; i < n*n; i++)
        {
            cout << (sol[i] == 1 ? "Q " : ". ");
            if((i+1) % n == 0) cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}
