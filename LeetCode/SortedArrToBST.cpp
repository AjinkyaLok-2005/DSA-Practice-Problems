#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* solve(int s, int e, vector<int>& nums)
    {
        int mid = (s+e)/2; 

        TreeNode* root = new TreeNode(nums[mid]);

        root -> left = solve(0, mid-1, nums);

        root -> right = solve(mid+1, nums.size()-1, nums);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();

        return solve(0, -1, nums);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = s.sortedArrayToBST(nums);

    return 0;
}