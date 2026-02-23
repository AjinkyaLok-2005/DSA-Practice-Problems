#include<iostream>
using namespace std;


// Definition for a binary tree node.
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
    void flatten(TreeNode* root) {
        TreeNode* current = root;

        while (current != NULL)
        {
            if (current->left != NULL)
            {
                // Find the predecessor (rightmost node in left subtree)
                TreeNode* predecessor = current->left;
                while (predecessor->right != NULL)
                {
                    predecessor = predecessor->right;
                }

                // Connect the right subtree after predecessor
                predecessor->right = current->right;

                // Move left subtree to the right
                current->right = current->left;
                current->left = NULL;
            }

            // Print current node
            // cout << current->data << " ";

            // Move to the right
            current = current->right;
        }
    }
};

int main()
{
    TreeNode * root = NULL;

    // Build the tree here (you can implement a function to build the tree)

    Solution obj;
    obj.flatten(root);

    // Print the flattened tree (you can implement a function to print the tree)

    return 0;
}