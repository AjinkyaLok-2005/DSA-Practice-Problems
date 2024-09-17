#include<iostream>
#include<vector>

using namespace std;

 vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) 
    {
        vector<vector<int>> result(m, vector<int>(n));

        if(original.size() != m*n)
        {
            return {};
        }
        
        // //Method 1
        // int idx = 0;
        // for(int i = 0; i < m; i++)
        // {
        //     for(int j = 0; j < n; j++)
        //     {
        //         result[i][j] = original[idx];
        //         idx++;
        //     }
        // }

        //Method 2
        for(int i = 0; i < original.size(); i++)
        {
            int row = i/n;
            int col = i%n;

            result[row][col] = original[i];
        }
        return result;
    }

int main()
{
    vector<int> arr = {1, 2, 3, 4}; 
    int m = 2;
    int n = 2;

    vector<vector<int>> result = construct2DArray(arr, m, n);

    // Print the 2D array
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}