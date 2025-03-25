#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

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
    root -> right  = buildTree(root -> right);

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

Node * lowestCommonAncestor(Node * root, int p, int q)
{
    //base case
    if(root == NULL)
    {
        return NULL;
    }
    
    if(root -> data == p || root -> data == q)
    {
        return root;
    }

    Node * leftAns = lowestCommonAncestor(root -> left, p, q);
    Node * rightAns = lowestCommonAncestor(root -> right, p, q);

    if(leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if(leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    Node * root = NULL;
    root = buildTree(root);
    //3 5 6 -1 -1 2 7 -1 -1 4 -1 -1 1 0 -1 -1 8 -1 -1 

    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);

    int p = 5;
    int q = 1;

    Node * result = lowestCommonAncestor(root, p, q);
    cout << "The LCA of nodes " << p << " and " << q << " is " << result -> data << endl;

    return 0;
}