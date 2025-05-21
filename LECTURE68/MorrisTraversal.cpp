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

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
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

Node * findPredecessor(Node * root, Node * current)
{
    Node * temp = current -> left;
    while(temp -> right != NULL && temp->right != current)
    {
        temp = temp -> right;
    }
    return temp;
}

void MorrisTraversal(Node* root)
{
    Node * current = root;

    while(current != NULL)
    {
        if(current -> left == NULL)
        {
            cout << current -> data << " ";
            current = current -> right;
        }
        else
        {
            Node * predecessor = findPredecessor(root, current);
            if(predecessor -> right == NULL)
            {
                predecessor -> right = current;
                current = current -> left;
            }
            else
            {
                predecessor -> right = NULL;
                cout << current -> data << " ";
                current = current -> right;
            }
        }
    }
}

int main()
{
    Node * root = NULL;

    root = buildTree(root);

    cout << endl;
    cout << "Morris Traversal for the above tree is: " << endl;

    MorrisTraversal(root);
    

    return 0;
}