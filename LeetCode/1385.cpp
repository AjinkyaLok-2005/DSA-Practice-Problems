#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;

        for(int i = 0; i < arr1.size(); i++)
        {
            int possible = true;

            for(int j = 0; j < arr2.size(); j++)
            {
                int diff = abs(arr1[i] - arr2[j]);

                if(diff <= d)
                {
                    possible = false;
                    break;
                }
            }

            if(possible)
                ans++;
        }

        return ans;
    }
};

int main() {
    vector<int> arr1 = {4, 5, 8};
    vector<int> arr2 = {10, 9, 1, 8};
    int d = 2;

    Solution obj;

    int result = obj.findTheDistanceValue(arr1, arr2, d);

    cout << "Distance Value: " << result << endl;

    return 0;
}