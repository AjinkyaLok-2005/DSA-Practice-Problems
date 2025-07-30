#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node
{
    public:
    int data;
    Node * left;
    Node * right;

    Node(int d)
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node * InsertIntoBST(Node * root, int d)
{
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if(d > root -> data)
    {
        root -> right = InsertIntoBST(root -> right, d);
    }
    else
    {
        root -> left = InsertIntoBST(root -> left, d); 
    }
    return root;
}

void takeInput(Node * & root)
{
    int data;
    cin >> data;

    while(data != -1)
    {
        root = InsertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node * root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node * temp = q.front();

        q.pop();

        if(temp == NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp -> data << " ";
            if(temp -> left)
            {
                q.push(temp -> left);
            }
            if(temp -> right)
            {
                q.push(temp -> right);
            }
        }
    }
}

bool isBST(Node* root, long long min, long long max)
{
    //base case
    if(root == NULL)
    {
        return true;
    }

//     A Binary Search Tree (BST), by standard definition, requires that:

// All nodes in the left subtree must have values strictly less than the current node’s value.

// All nodes in the right subtree must have values strictly greater than the current node’s value.

//Hence <= or >= will not work only < or > 

    if(root -> data > min && root -> data < max)
    {
        bool left = isBST(root -> left, min, root -> data);
        bool right = isBST(root -> right, root -> data, max);
        return left && right;
    }

    else
    {
        return false;
    }
}

bool validateBST(Node * root)
{
    // Also, to avoid potential integer overflow issues when using INT_MIN and INT_MAX, it's better to use long long as the range bounds.
    return isBST(root, LLONG_MIN, LLONG_MAX);

}

Node * buildTree(Node * root)
{
    cout << "Enter the data : " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data for inserting in right of " << data << endl;
    root -> right = buildTree(root -> right);
    return root;
}

int main()
{
    Node * root = NULL;

    // cout << "Enter data to create Tree: " << endl;
    // takeInput(root);

    root = buildTree(root);

    cout << "Printing the BST: " << endl;
    levelOrderTraversal(root);

    bool ans = validateBST(root);

    if(ans)
    {
        cout << "Tree is a valid BST " << endl;
    }
    else
    {
        cout << "Tree is not a valid BST " << endl;
    }
    
    return 0;
}