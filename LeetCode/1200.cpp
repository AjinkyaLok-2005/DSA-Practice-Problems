#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> result;

        sort(begin(arr), end(arr));

        int minDiff = INT_MAX;

        for (int i = 0; i < n - 1; i++)
        {
            minDiff = min(minDiff, arr[i + 1] - arr[i]);
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i + 1] - arr[i] == minDiff)
            {
                result.push_back({arr[i], arr[i + 1]});
            }
        }

        return result;
    }
};

void printResult(vector<vector<int>>& res)
{
    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[" << res[i][0] << "," << res[i][1] << "]";
        if (i != res.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main()
{
    Solution sol;

    // Example 1
    vector<int> arr1 = {4, 2, 1, 3};
    auto res1 = sol.minimumAbsDifference(arr1);
    cout << "Test 1: ";
    printResult(res1);
    cout << "Expected: [[1,2],[2,3],[3,4]]" << endl << endl;

    // Example 2
    vector<int> arr2 = {1, 3, 6, 10, 15};
    auto res2 = sol.minimumAbsDifference(arr2);
    cout << "Test 2: ";
    printResult(res2);
    cout << "Expected: [[1,3]]" << endl << endl;

    // Example 3
    vector<int> arr3 = {3, 8, -10, 23, 19, -4, -14, 27};
    auto res3 = sol.minimumAbsDifference(arr3);
    cout << "Test 3: ";
    printResult(res3);
    cout << "Expected: [[-14,-10],[19,23],[23,27]]" << endl;

    return 0;
}