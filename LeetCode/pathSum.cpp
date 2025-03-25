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

Node * buildTree(Node * root)
{
    cout << "Enter the data: " << endl;
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


bool solve(Node * root, int sum, int targetSum)
{
    //base case
    if(!root)
    {
        return false;
    }
    sum += root -> data;

    if(!root->left && !root->right){
        return sum == targetSum;
    }

    return solve(root -> left, sum, targetSum) || solve(root -> right, sum, targetSum);

}

bool hasPathSum(Node* root, int targetSum) 
{
    int sum = 0;
    return solve(root, sum, targetSum);
    
}


int main()
{
    Node* root = NULL;

    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1

    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);

    bool result = hasPathSum(root, 14);
    if(result)
    {
        cout << "Target Sum found: " << endl;
    }
    else
    {
        cout << "Target Sum not Found " << endl;
    }
    return 0;
}
