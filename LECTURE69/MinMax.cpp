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

Node* insertIntoBST(Node * root, int d)
{
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if(d > root -> data)
    {
        root -> right = insertIntoBST(root -> right, d);
    }
    else
    {
        root -> left = insertIntoBST(root -> left, d);
    }
    return root;
}

void takeInput(Node* & root)
{
    int data;
    cin >> data;

    while(data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

Node* minVal(Node* root)
{
    Node* temp = root;

    while(temp -> left != NULL)
    {
        temp = temp -> left;
    }
    return temp;
}

Node * maxVal(Node* root)
{
    Node * temp = root;
    while(temp -> right != NULL)
    {
        temp = temp -> right;
    }
    return temp;
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

int main()
{
    Node * root = NULL;

    cout << "Enter data to create BST: " << endl;
    takeInput(root);

    cout << "Printing the BST: " << endl;
    levelOrderTraversal(root);

    cout << endl;

    cout << "Min value is " << minVal(root) -> data << endl;
    cout << "Max value is " << maxVal(root) -> data << endl;

    return 0;
}