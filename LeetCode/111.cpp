#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:

    // BFS Approach
    int minDepthBFS(TreeNode* root) {

        if(root == NULL)
            return 0;

        queue<TreeNode*> que;
        que.push(root);

        int depth = 1;

        while(!que.empty())
        {
            int n = que.size();

            while(n--)
            {
                TreeNode* temp = que.front();
                que.pop();

                if(temp->left == NULL && temp->right == NULL)
                    return depth;

                if(temp->left != NULL)
                    que.push(temp->left);

                if(temp->right != NULL)
                    que.push(temp->right);
            }

            depth++;
        }

        return -1;
    }


    // DFS Approach
    int minDepthDFS(TreeNode* root) {

        if(root == NULL)
            return 0;

        if(root->left == NULL && root->right == NULL)
            return 1;

        int L;
        int R;

        if(root->left != NULL)
        {
            L = minDepthDFS(root->left);
        }
        else
        {
            L = INT_MAX;
        }

        if(root->right != NULL)
        {
            R = minDepthDFS(root->right);
        }
        else
        {
            R = INT_MAX;
        }

        return 1 + min(L, R);
    }
};


int main() {

    /*
            1
           / \
          2   3
         /
        4
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);

    Solution obj;

    // BFS Call
    // cout << "Minimum Depth (BFS): "
    //      << obj.minDepthBFS(root) << endl;

    // DFS Call
    cout << "Minimum Depth (DFS): "
         << obj.minDepthDFS(root) << endl;

    return 0;
}