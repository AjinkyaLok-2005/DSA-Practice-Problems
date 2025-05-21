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


void FlattenTreeToLinkedList(Node* root)
{
    Node* current = root;

    while (current != NULL)
    {
        if (current->left != NULL)
        {
            // Find the predecessor (rightmost node in left subtree)
            Node* predecessor = current->left;
            while (predecessor->right != NULL)
            {
                predecessor = predecessor->right;
            }

            // Connect the right subtree after predecessor
            predecessor->right = current->right;

            // Move left subtree to the right
            current->right = current->left;
            current->left = NULL;
        }

        // Print current node
        cout << current->data << " ";

        // Move to the right
        current = current->right;
    }
}


int main()
{
    Node * root = NULL;

    root = buildTree(root);

    cout << endl;
    cout << "Flatten Bianry Tree To Linked List: " << endl;

    FlattenTreeToLinkedList(root);
    

    return 0;
}