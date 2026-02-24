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
    int solve(TreeNode* root, int val)
    {
        if(root == NULL)
            return 0;

        val = (2 * val) + root -> val;

        if(root -> left == NULL && root -> right == NULL)
            return val;

        return solve(root -> left, val) + solve(root -> right, val);
    }

    int sumRootToLeaf(TreeNode* root) {
        int val = 0;

        return solve(root, val);
    }
};

int main()
{
    TreeNode * root = NULL;

    // Build the tree here (you can implement a function to build the tree)

    Solution obj;
    int result = obj.sumRootToLeaf(root);

    cout << "Sum of root-to-leaf binary numbers: " << result << endl;

    return 0;
}