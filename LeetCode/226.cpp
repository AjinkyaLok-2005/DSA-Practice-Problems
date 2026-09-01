#include <iostream>
#include <queue>
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
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL)
            return root;

        swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

// Level-order traversal to print the tree
void printTree(TreeNode* root) {
    if(root == NULL) {
        cout << "[]";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    cout << "[";

    while(!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if(current != NULL) {
            cout << current->val << " ";
            q.push(current->left);
            q.push(current->right);
        }
        else {
            cout << "null ";
        }
    }

    cout << "]";
}

int main() {

    // Creating the tree:
    //
    //         4
    //        / \
    //       2   7
    //      / \ / \
    //     1  3 6  9

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Original tree: ";
    printTree(root);

    cout << endl;

    Solution sol;
    root = sol.invertTree(root);

    cout << "Inverted tree: ";
    printTree(root);

    cout << endl;

    return 0;
}