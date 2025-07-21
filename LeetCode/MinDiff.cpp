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

void inorder(Node *root, vector<int> & in)
{
    //base case
    if(root == NULL)
    {
        return;
    }

    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

int getMinimumDifference(Node* root) 
{
    vector<int> in;
    inorder(root, in);
    int diff = INT_MAX;
    for(int i = 0; i < in.size() - 1; i++)
    {
        int ndiff = in[i+1] - in[i];
        if(ndiff < diff)
        {
            diff = ndiff;
        }
    }
    return diff;
}

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

int main()
{
    Node* root = NULL;
    
    cout << "Enter data to create Tree: " << endl;
    takeInput(root);

    int ans = getMinimumDifference(root);

    cout << "The Minimum Absolute Difference between nodes in the BST is : " << ans << endl;
    
    return 0;
}
