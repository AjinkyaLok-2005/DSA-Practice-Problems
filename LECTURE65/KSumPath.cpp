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

void solve(Node * root, int k, int& count, vector<int> path)
{
    //base case
    if(root == NULL)
    {
        return;
    }

    path.push_back(root -> data);
        
        solve(root -> left, k, count, path);
        
        solve(root -> right, k, count, path);
        
        int size = path.size();
        int sum = 0;
        
        for(int i = size-1; i >= 0; i--)
        {
            sum += path[i];
            if(sum == k)
            {
                count++;
            }
        }
        
        path.pop_back();
}

int sumK(Node * root, int k)
{
    vector<int> path;
    int count = 0;

    solve(root, k, count, path);
    return count;
}

int main()
{
    Node * root = NULL;
    root = buildTree(root);
    //8 4 3 3 -1 -1 -2 -1 -1 2 -1 1 -1 -1 5 -1 2 -1 -1 

    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);

    int k = 7;

    int result = sumK(root, k);
    cout << "The count is: " << result << endl;

    return 0;
}