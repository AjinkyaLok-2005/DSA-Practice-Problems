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
int findPosition(int in[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == element)
            return i;
    }
    return -1;
}

// Recursive function to build tree from inorder and preorder
Node *solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n)
{
    if (index >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = pre[index++];
    Node *root = new Node(element);

    int position = findPosition(in, element, n);

    root->left = solve(in, pre, index, inorderStart, position - 1, n);
    root->right = solve(in, pre, index, position + 1, inorderEnd, n);

    return root;
}

// Builds tree and returns root
Node *constructTree(int in[], int pre[], int n)
{
    int preOrderIndex = 0;
    return solve(in, pre, preOrderIndex, 0, n - 1, n);
}

// MAIN FUNCTION
int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int inorder[n], preorder[n];
    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }

    cout << "Enter preorder traversal: ";
    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }

    Node *root = constructTree(inorder, preorder, n);

    cout << "Level Order Traversal of Constructed Tree: \n";
    levelOrderTraversal(root);

    return 0;
}
