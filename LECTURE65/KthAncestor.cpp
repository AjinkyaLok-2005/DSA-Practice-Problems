#include<iostream>
#include<queue>
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


Node * buildTree(Node * root)
{
    cout << "Enter the data: " << endl;
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

Node* solve(Node* root, int &k, int node)
{
    //base case
    if(root == NULL)
    {
        return NULL;
    }
    
    if(root -> data == node)
    {
        return root;
    }
    
    Node * leftAns = solve(root -> left, k, node);
    Node * rightAns = solve(root -> right, k, node);
    
    if(leftAns != NULL && rightAns == NULL)
    {
        k--;
        if(k <= 0)
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node* ans = solve(root, k, node);
    if(ans == NULL || ans -> data == node)
    {
        return -1;
    }
    else
    {
        return ans -> data; 
    }
}

int main()
{
    Node * root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 -1 -1

    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);

    int k = 2;
    int node = 4;

    int result = kthAncestor(root, k, node);
    cout << k << " ancestor of " << node << " is " << result;

    return 0;
}