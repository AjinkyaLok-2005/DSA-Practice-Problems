#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int n;

    void rotate(vector<vector<int>>& mat)
    {
        //Transpose
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
               swap(mat[i][j], mat[j][i]); 
            }
        }

        //Reverse each row
        for(int i = 0; i < n; i++)
        {
            reverse(mat[i].begin(), mat[i].end());
        }

    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n = mat.size();

        for(int c = 0; c < 4; c++)
        {
            bool equal = true;

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(mat[i][j] != target[i][j])
                    {
                        equal = false;
                        break;
                    }
                }
                if(!equal)
                    break;
            }

            if(equal)
                return true;

            rotate(mat);
        }

        return false;
    }
};

int main()
{
    Solution obj;

    vector<vector<int>> mat = {
        {0, 1},
        {1, 0}
    };

    vector<vector<int>> target = {
        {1, 0},
        {0, 1}
    };

    if(obj.findRotation(mat, target))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}