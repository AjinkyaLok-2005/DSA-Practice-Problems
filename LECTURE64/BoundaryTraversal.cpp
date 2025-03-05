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

void traverseLeft(Node* root, vector<int> & ans)
{
    //base case
    if((root == NULL) || (root -> left == NULL && root -> right == NULL))
    {
        return;
    }

    ans.push_back(root -> data);
    if(root -> left)
    {
        traverseLeft(root -> left, ans);
    }
    else
    {
        traverseLeft(root -> right, ans);
    }
}  

void traverseLeaf(Node * root, vector<int> &ans)
{
    //base case
    if(root == NULL)
    {
        return;
    }

    if(root -> left == NULL && root -> right == NULL)
    {
        ans.push_back(root -> data);
        return;
    }

    traverseLeaf(root -> left, ans);
    traverseLeaf(root -> right, ans);
}

void traverseRight(Node* root, vector<int> & ans)
{
    //base case
    if((root == NULL) || (root -> left == NULL && root -> right == NULL))
    {
        return;
    }

    if(root -> right)
    {
        traverseRight(root -> right, ans);
    }
    else
    {
        traverseRight(root -> left, ans);
    }
}

vector<int> boundary(Node * root)
{
    vector<int> ans;
    if(root == NULL)
    {
        return ans;
    }

    ans.push_back(root -> data);

    //left part print/store
    traverseLeft(root -> left, ans);

    //traverse leaf node]

    //left subtree
    traverseLeaf(root -> left, ans);
    //right subtree
    traverseLeaf(root -> right, ans);

    //traverse right part
    traverseRight(root -> right, ans);

    return ans;

}

int main()
{
    // Creating a sample binary tree
    Node * root = NULL;

    root = buildTree(root);
    //1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1

    // Performing Level Order Traversal
    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);

    // Performing Boundary Traversal
    cout << "\nBoundary Traversal:" << endl;
    vector<int> boundaryTraversal = boundary(root);
    for (int val : boundaryTraversal)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;

    return 0;
}