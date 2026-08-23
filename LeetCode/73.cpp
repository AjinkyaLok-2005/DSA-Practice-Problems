#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRowImpacted = false;
        bool firstColImpacted = false;

        // Check if first row is impacted
        for (int col = 0; col < n; col++) {
            if (matrix[0][col] == 0) {
                firstRowImpacted = true;
                break;
            }
        }

        // Check if first column is impacted
        for (int row = 0; row < m; row++) {
            if (matrix[row][0] == 0) {
                firstColImpacted = true;
                break;
            }
        }

        // Set the markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set zeroes using the markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Set first row to zero if it was originally impacted
        if (firstRowImpacted) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Set first column to zero if it was originally impacted
        if (firstColImpacted) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    Solution obj;

    // Apply the algorithm
    obj.setZeroes(matrix);

    // Print the resulting matrix
    cout << "Matrix after setting zeroes:\n";

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}