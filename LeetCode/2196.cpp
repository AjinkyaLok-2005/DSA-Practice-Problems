#include<iostream>
#include<vector>
#include<unordered_map>
#include<ordered_map>
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childSet;

        for(vector<int>& vec : descriptions)
        {
            int parent = vec[0];
            int child = vec[1];
            int isLeft = vec[2];

            if(mp.find(parent) == mp.end())
            {
                mp[parent] = new TreeNode(parent);
            }

            if(mp.find(child) == mp.end())
            {
                mp[child] = new TreeNode(child);
            }

            if(isLeft == 1) //left Child
            {
                mp[parent] -> left = mp[child];
            }
            else //right child
            {
                mp[parent] -> right = mp[child];
            }

            childSet.insert(child);
        }

        //Root finding
        for(vector<int>& vec: descriptions)
        {
            int parent = vec[0];
            if(childSet.find(parent) == childSet.end())
            {
                return mp[parent];
            }
        }

        return NULL;
    }
};

void preorder(TreeNode* root)
{
    if(root == nullptr)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    vector<vector<int>> descriptions = {
        {20, 15, 1},
        {20, 17, 0},
        {15, 10, 1},
        {15, 12, 0}
    };

    Solution obj;

    TreeNode* root = obj.createBinaryTree(descriptions);

    cout << "Preorder Traversal: ";
    preorder(root);

    return 0;
}