#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int n;

    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& output, int index)
    {
        // Base case
        if(target == 0)
        {
            ans.push_back(output);
            return;
        }

        if(index >= n || target < 0)
        {
            return;
        }

        // Include current element
        output.push_back(candidates[index]);
        solve(candidates, target - candidates[index], ans, output, index);

        // Backtrack
        output.pop_back();

        // Exclude current element
        solve(candidates, target, ans, output, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        n = candidates.size();

        vector<vector<int>> ans;
        vector<int> output;

        solve(candidates, target, ans, output, 0);

        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter number of candidates: ";
    cin >> n;

    vector<int> candidates(n);

    cout << "Enter the candidates: ";
    for(int i = 0; i < n; i++)
    {
        cin >> candidates[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution obj;
    vector<vector<int>> ans = obj.combinationSum(candidates, target);

    cout << "\nCombinations are:\n";

    if(ans.empty())
    {
        cout << "No combination found.\n";
    }
    else
    {
        for(auto &vec : ans)
        {
            cout << "[ ";
            for(int x : vec)
            {
                cout << x << " ";
            }
            cout << "]\n";
        }
    }

    return 0;
}