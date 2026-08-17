#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
    if(a[0] != b[0])
        return a[0] < b[0];

    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals), cmp);

        int i = 1;
        int n = intervals.size();

        int count = 0;

        int comp = 0;

        while(i < n)
        {
            if(intervals[i][0] < intervals[comp][1])
            {
                count++;
                {
                    if(intervals[i][1] < intervals[comp][1])
                    {
                        comp = i;
                    }
                }
            }
            else
            {
                comp = i;
            }

            i++;
        }

        return count;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> intervals1 = {{1,2},{2,3},{3,4},{1,3}};
    cout << "Test 1 (expected 1): " << sol.eraseOverlapIntervals(intervals1) << endl;

    // Example 2
    vector<vector<int>> intervals2 = {{1,2},{1,2},{1,2}};
    cout << "Test 2 (expected 2): " << sol.eraseOverlapIntervals(intervals2) << endl;

    // Example 3
    vector<vector<int>> intervals3 = {{1,2},{2,3}};
    cout << "Test 3 (expected 0): " << sol.eraseOverlapIntervals(intervals3) << endl;

    // Edge case: one huge interval swallowing everything
    vector<vector<int>> intervals4 = {{1,100},{2,3},{3,4}};
    cout << "Test 4 (expected 1): " << sol.eraseOverlapIntervals(intervals4) << endl;

    // Edge case: negative numbers
    vector<vector<int>> intervals5 = {{-50,-20},{-30,-10},{0,10},{5,15}};
    cout << "Test 5 (expected 2): " << sol.eraseOverlapIntervals(intervals5) << endl;

    // Edge case: single interval
    vector<vector<int>> intervals6 = {{1,5}};
    cout << "Test 6 (expected 0): " << sol.eraseOverlapIntervals(intervals6) << endl;

    // Edge case: unsorted input with negatives
    vector<vector<int>> intervals7 = {{-1,1},{-5,3},{0,2},{1,2},{3,4}};
    cout << "Test 7: " << sol.eraseOverlapIntervals(intervals7) << endl;

    return 0;
}