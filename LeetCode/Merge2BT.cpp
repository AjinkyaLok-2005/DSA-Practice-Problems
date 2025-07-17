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

Node * mergeTrees(Node* r1, Node* r2)
{
    if(r1 == NULL)
    {
        return r2;
    }

    if(r2 == NULL)
    {
        return r1;
    }

    r1 -> left = mergeTrees(r1 -> left, r2 -> left);
    r1 -> data += r2 -> data;
    r1 -> right = mergeTrees(r1 -> right, r2 -> right);

    return r1;
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
    Node *root1 = NULL;
    Node *root2 = NULL;

    cout << "Enter data to create Tree 1: " << endl;
    takeInput(root1);

    cout << "Enter data to create Tree 2: " << endl;
    takeInput(root2);

    cout << "Printing BST 1:" << endl;
    levelOrderTraversal(root1);

    cout << "Printing BST 2:" << endl;
    levelOrderTraversal(root2);

    Node *ans = mergeTrees(root1, root2);

    cout << "\nPrinting the Merged Tree: " << endl;
    levelOrderTraversal(ans);
    return 0;
}
