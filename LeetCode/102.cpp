#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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

    // BFS
    void BFS(TreeNode* root, vector<vector<int>>& result)
    {
        if(root == NULL)
            return;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            int n = que.size();
            vector<int> temp;

            while(n--)
            {
                TreeNode* top = que.front();
                que.pop();

                temp.push_back(top->val);

                if(top->left != NULL)
                    que.push(top->left);

                if(top->right != NULL)
                    que.push(top->right);
            }

            result.push_back(temp);
        }
    }


    // DFS
    void DFS(TreeNode* root, int depth, vector<vector<int>>& result)
    {
        if(root == NULL)
            return;

        if(result.size() == depth)
        {
            result.push_back({});
        }

        result[depth].push_back(root->val);

        DFS(root->left, depth + 1, result);
        DFS(root->right, depth + 1, result);
    }


    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;

        // BFS(root, result);

        DFS(root, 0, result);

        return result;
    }
};


int main()
{
    /*
            3
           / \
          9   20
             /  \
            15   7
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);


    Solution obj;

    vector<vector<int>> result = obj.levelOrder(root);


    // Print result
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}