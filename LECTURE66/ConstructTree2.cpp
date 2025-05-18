#include<iostream>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// Helper to find index of element in inorder[]
    int findpos(vector<int> &inorder, int target, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == target) {
                return i;
            }
        }
        return -1;
    }

// Recursive function to build tree from inorder and preorder
Node* construct(vector<int> &inorder, vector<int> &postorder, int start, int end, int &index) {
    if (start > end || index < 0) {
        return NULL;
    }
        
    int rootVal = postorder[index];
    Node* root = new Node(rootVal);
    int pos = findpos(inorder, rootVal, start, end);
        
    index--; // Move to the next root in postorder (right subtree first)
        
    // Right subtree must be built before left (since postorder is L-R-Root)
    root->right = construct(inorder, postorder, pos + 1, end, index);
    root->left = construct(inorder, postorder, start, pos - 1, index);
        
    return root;
}
    
Node* buildTree(vector<int> inorder, vector<int> postorder) {
    int n = inorder.size();
    int index = n - 1; // Start from the last element (root)
    return construct(inorder, postorder, 0, n - 1, index);
}

// MAIN FUNCTION
int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> inorder(n), postorder(n);

    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }

    cout << "Enter postorder traversal: ";
    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }

    Node * root = buildTree(inorder, postorder);

    cout << "Level Order Traversal of Constructed Tree: \n";
    levelOrderTraversal(root);

    return 0;
}

