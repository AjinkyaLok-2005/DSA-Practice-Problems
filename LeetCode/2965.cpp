#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> freq(n * n + 1, 0);
        vector<int> result(2);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                freq[grid[i][j]]++;
            }
        }

        for(int num = 1; num <= n * n; num++)
        {
            if(freq[num] == 2)
            {
                result[0] = num;
            }
            else if(freq[num] == 0)
            {
                result[1] = num;
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 3},
        {2, 2}
    };

    Solution obj;

    vector<int> result = obj.findMissingAndRepeatedValues(grid);

    cout << "Repeated: " << result[0] << endl;
    cout << "Missing: " << result[1] << endl;

    return 0;
}