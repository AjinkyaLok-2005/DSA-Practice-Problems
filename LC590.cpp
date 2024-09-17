#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    // Function to perform postorder traversal
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        // Helper function to perform recursive traversal
        postorderTraversal(root, result);
        return result;
    }

    void postorderTraversal(Node* node, vector<int>& result) {
        // Visit all the children first
        for (Node* child : node->children) {
            postorderTraversal(child, result);
        }
        // Visit the current node
        result.push_back(node->val);
    }
};

int main() {
    // Creating the tree:
    //          1
    //        / | \
    //       3  2  4
    //      / \
    //     5   6
    Node* root = new Node(1);
    root->children = { new Node(3), new Node(2), new Node(4) };
    root->children[0]->children = { new Node(5), new Node(6) };

    // Solution instance
    Solution sol;
    
    // Get postorder traversal
    vector<int> result = sol.postorder(root);

    // Output the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl; // Expected output: 5 6 3 2 4 1

    return 0;
}
