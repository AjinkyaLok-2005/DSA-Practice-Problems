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

Node * LCAinaBST(Node * root, Node * P, Node * Q)
{
    //base case
    if(root == NULL)
    {
        return NULL;
    }

    if(root -> data < P -> data && root -> data < Q -> data)
    {
        return LCAinaBST(root -> right, P, Q);
    }

    if(root -> data > P -> data && root -> data > Q -> data)
    {
        return LCAinaBST(root -> left, P, Q);
    }

    return root;
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

    cout << "Enter data to create BST (-1 to stop): " << endl;
    takeInput(root);

    cout << "Printing the BST: " << endl;
    levelOrderTraversal(root);

    int p, q;
    cout << "Enter first node value for LCA: ";
    cin >> p;
    cout << "Enter second node value for LCA: ";
    cin >> q;

    // Function to find the node pointer in the BST
    auto findNode = [](Node* root, int val) -> Node* {
        while (root != NULL) {
            if (val == root->data) return root;
            else if (val < root->data) root = root->left;
            else root = root->right;
        }
        return NULL; // if not found
    };

    Node* P = findNode(root, p);
    Node* Q = findNode(root, q);

    Node* lca = LCAinaBST(root, P, Q);

    if (lca != NULL)
        cout << "The LCA of " << p << " and " << q << " is: " << lca->data << endl;
    else
        cout << "LCA not found in the BST." << endl;

    return 0;
}
