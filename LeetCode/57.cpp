#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        int n = intervals.size();

        int x = newInterval[0];
        int y = newInterval[1];

        vector<vector<int>> result;

        while(i < n && intervals[i][1] < x)
        {
            result.push_back(intervals[i]);
            i++;
        }

        while(i < n && intervals[i][0] <= y)
        {
            x = min(x, intervals[i][0]);
            y = max(y, intervals[i][1]);
            i++;
        }

        result.push_back({x, y});

        while(i < n)
        {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};

void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << "," << result[i][1] << "]";
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> intervals1 = {{1,3},{6,9}};
    vector<int> newInterval1 = {2,5};
    cout << "Test 1 (expected [[1,5],[6,9]]): ";
    printResult(sol.insert(intervals1, newInterval1));

    // Example 2
    vector<vector<int>> intervals2 = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval2 = {4,8};
    cout << "Test 2 (expected [[1,2],[3,10],[12,16]]): ";
    printResult(sol.insert(intervals2, newInterval2));

    // Edge case: empty intervals
    vector<vector<int>> intervals3 = {};
    vector<int> newInterval3 = {5,7};
    cout << "Test 3 (expected [[5,7]]): ";
    printResult(sol.insert(intervals3, newInterval3));

    // Edge case: newInterval goes at the very start
    vector<vector<int>> intervals4 = {{3,5},{12,15}};
    vector<int> newInterval4 = {1,2};
    cout << "Test 4 (expected [[1,2],[3,5],[12,15]]): ";
    printResult(sol.insert(intervals4, newInterval4));

    // Edge case: newInterval goes at the very end
    vector<vector<int>> intervals5 = {{1,2},{3,5}};
    vector<int> newInterval5 = {6,8};
    cout << "Test 5 (expected [[1,2],[3,5],[6,8]]): ";
    printResult(sol.insert(intervals5, newInterval5));

    return 0;
}