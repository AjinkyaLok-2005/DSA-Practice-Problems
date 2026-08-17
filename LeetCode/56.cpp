#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
    return a[0] < b[0]; 
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals), cmp);

        int i = 1;
        int n = intervals.size();

        vector<vector<int>> result;
        
        result.push_back(intervals[0]);

        while(i < n)
        {
            if(intervals[i][0] <= result.back()[1])
            {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else
            {
                result.push_back(intervals[i]);
            }

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
    vector<vector<int>> intervals1 = {{1,3},{2,6},{8,10},{15,18}};
    cout << "Test 1 (expected [[1,6],[8,10],[15,18]]): ";
    printResult(sol.merge(intervals1));

    // Example 2
    vector<vector<int>> intervals2 = {{1,4},{4,5}};
    cout << "Test 2 (expected [[1,5]]): ";
    printResult(sol.merge(intervals2));

    // Edge case: unsorted input
    vector<vector<int>> intervals3 = {{4,7},{1,4}};
    cout << "Test 3 (expected [[1,7]]): ";
    printResult(sol.merge(intervals3));

    // Edge case: single interval
    vector<vector<int>> intervals4 = {{1,4}};
    cout << "Test 4 (expected [[1,4]]): ";
    printResult(sol.merge(intervals4));

    // Edge case: no overlaps at all
    vector<vector<int>> intervals5 = {{1,2},{3,4},{5,6}};
    cout << "Test 5 (expected [[1,2],[3,4],[5,6]]): ";
    printResult(sol.merge(intervals5));

    return 0;
}