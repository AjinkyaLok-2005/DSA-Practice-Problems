#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int n;
    int t[23][23];

    // Returns the maximum score difference (Player1 - Player2)
    int maxDiff(vector<int>& nums, int l, int r) {

        if (l == r)
            return nums[l];

        if (t[l][r] != -1)
            return t[l][r];

        int take_left = nums[l] - maxDiff(nums, l + 1, r);
        int take_right = nums[r] - maxDiff(nums, l, r - 1);

        return t[l][r] = max(take_left, take_right);
    }

    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));

        return maxDiff(nums, 0, n - 1) >= 0;
    }
};

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    if (obj.predictTheWinner(nums))
        cout << "Player 1 can win (or tie)." << endl;
    else
        cout << "Player 1 cannot win." << endl;

    return 0;
}