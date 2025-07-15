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

void inorder(Node * root, vector<int> & in)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

Node * inorderToBST(int s, int e, vector<int> & in)
{
    //base case
    if(s > e)
    {
        return NULL;
    }

    int mid = (s+e)/2;
    Node * root = new Node(in[mid]);
    root -> left = inorderToBST(s, mid - 1, in);
    root -> right = inorderToBST(mid + 1, e, in);

    return root;
}

Node * balancedBST(Node * root)
{
    vector<int> inorderVal;
    inorder(root, inorderVal);

    return inorderToBST(0, inorderVal.size() - 1, inorderVal);
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

    Node * ans = balancedBST(root);

    cout << endl;

    cout << "Printing the Balanced BST: " << endl;
    levelOrderTraversal(ans);

    return 0;
}