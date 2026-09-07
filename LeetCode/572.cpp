#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool sameTree(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL)
            return true;

        if((root1 == NULL && root2 != NULL) ||
           (root1 != NULL && root2 == NULL))
            return false;

        if(root1->val != root2->val)
            return false;

        return sameTree(root1->left, root2->left) &&
               sameTree(root1->right, root2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if(root == NULL)
            return false;

        if(sameTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};

int main()
{
    // root = [3,4,5,1,2]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    // subRoot = [4,1,2]
    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution solution;

    bool result = solution.isSubtree(root, subRoot);

    cout << boolalpha;
    cout << "Is subRoot a subtree of root? " << result << endl;

    return 0;
}