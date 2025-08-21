#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>> &board, char val)
    {
        int n = board.size();

        //check row
        for(int i = 0; i < n; i++)
        {
            if(board[row][i] == val)
            {
                return false;
            }
        }

        //check column
        for(int i = 0; i < n; i++)
        {
            if(board[i][col] == val)
            {
                return false;
            }
        }

        //3x3 matrix
        int startRow = 3 * (row/3);
        int startCol = 3 * (col/3);

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[startRow + i][startCol + j] == val)
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < n; col++)
            {
                char val = board[row][col];
                if(val != '.')
                {
                    board[row][col] = '.';
                    if(!isSafe(row, col, board, val))
                    {
                        return false;
                    }
                    board[row][col] = val;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1: Valid Sudoku
    vector<vector<char>> validBoard = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    cout << "Valid Sudoku test: " << (solution.isValidSudoku(validBoard) ? "PASS" : "FAIL") << endl;
    
    // Test Case 2: Invalid Sudoku (duplicate in row)
    vector<vector<char>> invalidRowBoard = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'5','.','.','.','8','.','.','7','9'}  // Duplicate '5' in first column
    };
    
    cout << "Invalid Sudoku (row) test: " << (!solution.isValidSudoku(invalidRowBoard) ? "PASS" : "FAIL") << endl;
    
    // Test Case 3: Invalid Sudoku (duplicate in 3x3 box)
    vector<vector<char>> invalidBoxBoard = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','5','.','8','.','.','7','9'}  // Duplicate '5' in top-left 3x3 box
    };
    
    cout << "Invalid Sudoku (box) test: " << (!solution.isValidSudoku(invalidBoxBoard) ? "PASS" : "FAIL") << endl;
    
    // Test Case 4: Empty board (should be valid)
    vector<vector<char>> emptyBoard(9, vector<char>(9, '.'));
    cout << "Empty board test: " << (solution.isValidSudoku(emptyBoard) ? "PASS" : "FAIL") << endl;
    
    return 0;
}