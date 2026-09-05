#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        int j = n - 1;

        // Find the start of the non-decreasing suffix
        while (j > 0 && arr[j - 1] <= arr[j]) {
            j--;
        }

        int i = 0;
        int result = j;

        // Try keeping different non-decreasing prefixes
        while (i < j && (i == 0 || arr[i] >= arr[i - 1])) {

            // Find the first element in the suffix
            // that can come after arr[i]
            while (j < n && arr[i] > arr[j]) {
                j++;
            }

            // Remove elements between i and j
            result = min(result, j - i - 1);

            i++;
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {5, 4, 3, 2, 1};

    int result = sol.findLengthOfShortestSubarray(arr);

    cout << "Minimum length of subarray to remove: "
         << result << endl;

    return 0;
}