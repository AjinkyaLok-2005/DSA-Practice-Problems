#include<iostream>
#include<queue>
#include<vector>
#include<map>
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

    cout << "Enter data for inserting in left of: " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data for inserting in right of: " << data << endl;
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

vector<int> bottomView(Node * root)
{
    vector<int> ans;

    if(root == NULL)
    {
        return ans;
    }

    map<int, int> BottomNode;
    //mapping of horizontal distance and node data
    queue<pair<Node*, int> > q;

    q.push(make_pair(root, 0));

    while(!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();
        Node * frontNode = temp.first;
        int hd = temp.second;

        BottomNode[hd] = frontNode -> data;

        if(frontNode -> left)
        {
            q.push(make_pair(frontNode -> left, hd-1));
        }

        if(frontNode -> right)
        {
            q.push(make_pair(frontNode -> right, hd+1));
        }
    }

    for(auto i: BottomNode)
    {
        ans.push_back(i.second);
    }

    return ans;
}

int main()
{
    Node * root = NULL;
    root = buildTree(root);

    cout << "Level Order Traversal: " << endl;
    levelOrderTraversal(root);

    cout << endl;

    vector<int> ans = bottomView(root);

    cout << "Bottom view of the tree is: " << endl;

    for(int val: ans)
    {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}