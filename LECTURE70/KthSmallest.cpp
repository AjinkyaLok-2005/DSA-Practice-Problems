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

int solve(Node * root, int & i, int k)
{
    //base case
    if(root == NULL)
    {
        return -1;
    }

    int left = solve(root -> left, i, k);

    if(left != -1)
    {
        return left;
    }

    i++;
    if(i == k)
    {
        return root -> data;
    }

    return solve(root -> right, i, k);
}

int kthSmallest(Node * root, int k)
{
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
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

    cout << "Enter data to create Tree: " << endl;
    takeInput(root);

    // root = buildTree(root);

    cout << "Printing the BST: " << endl;
    levelOrderTraversal(root);

    int ans = kthSmallest(root, 3);

    cout << "The 3th smallest element in the given BST is " << ans << endl;
    
    return 0;
}