#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node * left;
    Node* right;

    Node(int d)
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

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

int countNodes(Node * root)
{
    if(root == NULL)
    {
        return 0;
    }
    
    int ans = 1 + countNodes(root -> left) + countNodes(root -> right);
    return ans;
}

bool isCBT(Node * root, int index, int cnt)
{
    if(root == NULL)
    {
        return true;
    }
    
    if(index >= cnt)
    {
        return false;
    }
    else
    {
        bool left = isCBT(root -> left, 2*index + 1, cnt);
        bool right = isCBT(root -> right, 2*index + 2, cnt);
        
        return(left && right);
    }
}

bool isMaxOrder(Node * root)
{
    if(root -> left == NULL && root -> right == NULL)
    {
        return true;
    }
    
    if(root -> right == NULL)
    {
        return (root -> data > root -> left -> data);
    }
    else
    {
        bool left = isMaxOrder(root -> left);
        bool right = isMaxOrder(root -> right);
        
        return (left && right && 
        (root -> data > root -> left -> data && root -> data > root -> right -> data));
    }
}

bool isHeap(Node* tree) {
    // code here
    int index = 0;
    int totalCount = countNodes(tree);
    if(isCBT(tree, index, totalCount) && isMaxOrder(tree))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Node * root = NULL;

    root = buildTree(root);
    // 97 46 12 6 -1 -1 9 -1 -1 3 -1 -1 37 7 -1 -1 31 -1 -1 

    cout << "Printing the Tree " << endl;
    levelOrderTraversal(root);

    bool ans = isHeap(root);

    if(ans)
    {
        cout << "Given Binary Tree is a Heap " << endl;
    }
    else
    {
        cout << "Given Binary Tree is not a Heap " << endl;
    }

    return 0;
}