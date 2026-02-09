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
    void inorder(TreeNode* root, vector<int> & in)
    {
        if(root == NULL)
            return;

        inorder(root -> left, in);
        in.push_back(root -> val);
        inorder(root -> right, in);
    }

    TreeNode* inorderToBST(int s, int e, vector<int> in)
    {
        if(s > e)
            return NULL;

        int mid = (s+e)/2;

        TreeNode* root = new TreeNode(in[mid]);
        root -> left = inorderToBST(s, mid-1, in);
        root -> right = inorderToBST(mid+1, e, in);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorderVal;

        inorder(root, inorderVal);

        return inorderToBST(0, inorderVal.size()-1, inorderVal);
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root -> right = new TreeNode(2);
    root -> right -> right = new TreeNode(3);
    root -> right -> right -> right = new TreeNode(4);
    root -> right -> right -> right -> right = new TreeNode(5);

    Solution obj;
    TreeNode* ans = obj.balanceBST(root);

    return 0;
}