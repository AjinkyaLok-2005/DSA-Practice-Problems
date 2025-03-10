//Sum of the longest Blood Line

#include<iostream>
#include<queue>
#include<climits>
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

void solve(Node * root, int sum, int & maxSum, int len, int & maxLen)
{
    //base case
    if(root == NULL)
    {
        if(len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }

        else if(len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum = sum + root -> data;

    solve(root -> left, sum, maxSum, len+1, maxLen);
    solve(root -> right, sum, maxSum, len+1, maxLen);
}

int sumOfLongRootToLeafPath(Node * root)
{
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = INT_MIN;

    solve(root, sum, maxSum, len, maxLen);

    return maxSum;
}

int main()
{
    Node* root = NULL;

    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1

    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);

    int result = sumOfLongRootToLeafPath(root);
    cout << "Sum of the longest bloodline: " << result << endl;

    return 0;
}
