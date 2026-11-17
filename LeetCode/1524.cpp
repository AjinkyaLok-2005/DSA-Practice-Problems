
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        int count = 0;
        int odd = 0;
        int even = 1;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += arr[i];

            if(sum % 2 == 0) {
                count = (count + odd) % MOD;
                even++;
            }
            else {
                count = (count + even) % MOD;
                odd++;
            }
        }

        return count;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = obj.numOfSubarrays(arr);

    cout << "Number of subarrays with odd sum: " << result << endl;

    return 0;
}
