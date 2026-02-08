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
    int dfs(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        int left = dfs(root -> left);
        if(left == -1)
            return -1;

        int right = dfs(root -> right);
        if(right == -1)
            return -1;

        int height = abs(left - right);

        if(height > 1)
            return -1;

        return 1 + max(left, right);

    }

    bool isBalanced(TreeNode* root) {
        if(dfs(root) == -1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);

    Solution obj;
    cout << obj.isBalanced(root);

    return 0;
}