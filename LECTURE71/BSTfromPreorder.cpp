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

Node * solve(vector<int>& preorder, int min, int max, int & i)
{
    //base case
    if(i >= preorder.size())
    {
        return NULL;
    }
    if(preorder[i] < min || preorder[i] > max)
    {
        return NULL;
    }
    
    Node* root = new Node(preorder[i++]);
    root -> left = solve(preorder, min, root -> data, i);
    root -> right = solve(preorder, root -> data, max, i); 
    return root;
}

Node * bstFromPreorder(vector<int>& preorder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;

    return solve(preorder, mini, maxi, i);
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

    // // root = buildTree(root);

    // cout << "Printing the BST: " << endl;
    // levelOrderTraversal(root);

    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    // vector<int> preorder = {1, 3};

    Node * ans = bstFromPreorder(preorder);

    cout << endl;

    cout << "Printing the Balanced BST: " << endl;
    levelOrderTraversal(ans);

    return 0;
}