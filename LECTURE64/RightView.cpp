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

void solve(Node * root, vector<int> & ans, int level)
{
    if(root == NULL)
    {
        return;
    }

    //we entered into a new level 
    if(level == ans.size())
    {
        ans.push_back(root -> data);
    }
    solve(root -> right, ans, level+1);
    solve(root -> left, ans, level+1);
}

vector<int> RightView(Node* root)
{
    vector<int> ans;
    solve(root, ans, 0);

    return ans;
}

int main()
{
    Node * root = NULL;
    root = buildTree(root);

    cout << "Level Order Traversal: " << endl;
    levelOrderTraversal(root);

    cout << endl;

    vector<int> ans = RightView(root);

    cout << "Right view of the tree is: " << endl;
    for(int val: ans)
    {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}
