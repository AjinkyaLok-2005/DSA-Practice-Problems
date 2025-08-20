#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>> &board, char val)
    {
        int n = board.size();

        // Check row
        for(int i = 0; i < n; i++)
        {
            if(board[row][i] == val)
                return false;
        }
        
        // Check column
        for(int i = 0; i < n; i++)
        {
            if(board[i][col] == val)
                return false;
        }

        // 3×3 matrix check
        int startRow = 3 * (row / 3);
        int startCol = 3 * (col / 3);
        
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[startRow + i][startCol + j] == val)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>> &board)
    {
        int n = board.size();

        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < n; col++)
            {
                // cell empty
                if(board[row][col] == '.')
                {
                    for(char val = '1'; val <= '9'; val++)
                    {
                        if(isSafe(row, col, board, val))
                        {
                            board[row][col] = val;

                            // recursive call
                            bool isSolvePossible = solve(board);

                            if(isSolvePossible)
                            {
                                return true;
                            }
                            else
                            {
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

// Helper function to print the Sudoku board
void printBoard(const vector<vector<char>>& board) {
    cout << "Solved Sudoku:" << endl;
    for(int i = 0; i < 9; i++) {
        if(i % 3 == 0 && i != 0) {
            cout << "------+-------+------" << endl;
        }
        for(int j = 0; j < 9; j++) {
            if(j % 3 == 0 && j != 0) {
                cout << "| ";
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    Solution sol;
    
    // Test case 1: Example Sudoku puzzle
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    cout << "Original Sudoku:" << endl;
    printBoard(board);
    
    sol.solveSudoku(board);
    
    cout << "Solved Sudoku:" << endl;
    printBoard(board);

    // Test case 2: Another puzzle
    vector<vector<char>> board2 = {
        {'.', '.', '.', '2', '6', '.', '7', '.', '1'},
        {'6', '8', '.', '.', '7', '.', '.', '9', '.'},
        {'1', '9', '.', '.', '.', '4', '5', '.', '.'},
        {'8', '2', '.', '1', '.', '.', '.', '4', '.'},
        {'.', '.', '4', '6', '.', '2', '9', '.', '.'},
        {'.', '5', '.', '.', '.', '3', '.', '2', '8'},
        {'.', '.', '9', '3', '.', '.', '.', '7', '4'},
        {'.', '4', '.', '.', '5', '.', '.', '3', '6'},
        {'7', '.', '3', '.', '1', '8', '.', '.', '.'}
    };

    cout << "\nAnother Sudoku puzzle:" << endl;
    printBoard(board2);
    
    sol.solveSudoku(board2);
    
    cout << "Solved:" << endl;
    printBoard(board2);

    return 0;
}