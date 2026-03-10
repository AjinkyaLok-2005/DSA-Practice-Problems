#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        int count = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 1)
                {
                    bool isRow = true;
                    bool isCol = true;

                    //for row
                    for(int col = 0; col < n; col++)
                    {
                        if(col != j && mat[i][col] != 0)
                        {
                            isRow = false;
                            break;
                        }
                    }

                    //for column
                    for(int row = 0; row < m; row++)
                    {
                        if(row != i && mat[row][j] != 0)
                        {
                            isCol = false;
                            break;
                        }
                    }

                    if(isRow && isCol)
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }

    int numSpecial(vector<vector<int>>& mat) {
        return solve(mat);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> mat = {{1,0,0}, {0,0,1}, {1,0,0}};
    cout << s.numSpecial(mat) << endl;

    return 0;
}
