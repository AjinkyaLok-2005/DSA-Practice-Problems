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

vector<int> verticalOrder(Node * root)
{
    map<int, map<int, vector<int> > > nodes;
    queue<pair<Node*, pair<int, int> > > q;
    vector<int> ans;

    if(root == NULL)
    {
        return ans;
    }

    q.push(make_pair(root, make_pair(0,0)));

    while(!q.empty())
    {
        pair<Node*, pair<int, int> > temp = q.front();
        q.pop();

        Node * frontNode = temp.first;
        //horizontal distance
        int hd = temp.second.first;
        //level
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode -> data);

        if(frontNode -> left)
        {
            q.push(make_pair(frontNode -> left, make_pair(hd-1, lvl+1)));
        }

        if(frontNode -> right)
        {
            q.push(make_pair(frontNode -> right, make_pair(hd+1, lvl+1)));
        }
    }

    for(auto i: nodes)
    {
        for(auto j:i.second)
        {
            for(auto k:j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main()
{
    Node * root = NULL;

    root = buildTree(root);
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1

    cout << "Level Order Traversal: " << endl;
    levelOrderTraversal(root); 

    vector<int> ans = verticalOrder(root);

    for(int val: ans)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
};