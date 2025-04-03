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

pair<int, int> solve(Node* root)
{
    //base case
    if(root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = solve(root -> left);
    pair<int, int> right = solve(root -> right);

    pair<int, int> res;

    res.first = root -> data + left.second + right.second;

    res.second = max(left.first, left.second) + max(right.first, right.second);

    return res;
}

int getMaxSum(Node * root)
{
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}

int main()
{
    Node * root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 -1 3 5 -1 -1 6 -1 -1  

    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);

    int result = getMaxSum(root);
    cout << "Max sum of non-adjacent nodes is " << result;

    return 0;
}