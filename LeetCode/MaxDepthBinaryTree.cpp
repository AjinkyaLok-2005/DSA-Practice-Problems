#include<iostream>
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
    int solve(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int left = solve(root -> left);
        int right = solve(root -> right);

        return 1 + max(left, right);
    }

    int maxDepth(TreeNode* root) {
        return solve(root);
    }
};

int main()
{
    TreeNode* root = new TreeNode(3);
    root -> left = new TreeNode(9);
    root -> right = new TreeNode(20);
    root -> right -> left = new TreeNode(15);
    root -> right -> right = new TreeNode(7);

    Solution s;
    cout << s.maxDepth(root) << endl;

    return 0;
}