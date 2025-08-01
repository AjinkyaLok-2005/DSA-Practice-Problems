#include<iostream>
#include<queue>
#include<vector>
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

void inorder(Node * root, vector<int> & inorderArr)
{
    //base case
    if(root == NULL)
    {
        return;
    }

    inorder(root -> left, inorderArr);
    inorderArr.push_back(root -> data);
    inorder(root -> right, inorderArr);
}

void preorderFill(Node * root, vector<int> inorderArr, int& index)
{
    //base case
    if(root == NULL)
    {
        return;
    }

    root -> data = inorderArr[index++];
    preorderFill(root -> left, inorderArr, index);
    preorderFill(root -> right, inorderArr, index);
}

Node * convertBSTtoMinHeap(Node* root)
{
    vector<int> inorderArr;

    inorder(root, inorderArr);

    int index = 0;

    preorderFill(root, inorderArr, index);

    return root;
}

int main()
{
    Node * root = NULL;

    cout << "Enter data to create Tree: " << endl;
    takeInput(root);

    cout << "Printing BST: " << endl;
    levelOrderTraversal(root);

    Node * ans = convertBSTtoMinHeap(root);

    cout << "Printing the Min Heap: " << endl;
    levelOrderTraversal(ans);

    return 0;
}