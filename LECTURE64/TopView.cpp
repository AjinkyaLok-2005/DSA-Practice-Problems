#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

class Node
{
    public:
    int data;
    Node * right;
    Node * left;

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

vector<int> topView(Node * root)
{
    vector<int> ans;

    if(root == NULL)
    {
        return ans;
    }

    map<int, int> topNode;
    //mapping of horizontal distance and node data
    queue<pair<Node*, int> > q;

    q.push(make_pair(root, 0));

    while(!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();
        Node * frontNode = temp.first;
        int hd = temp.second;

        //if one mapping is present for a HD, then do nothing
        //else make an entry for that HD in the map
        if(topNode.find(hd) == topNode.end())
        {
            topNode[hd] = frontNode -> data;
        }

        if(frontNode -> left)
        {
            q.push(make_pair(frontNode -> left, hd-1));
        }

        if(frontNode -> right)
        {
            q.push(make_pair(frontNode -> right, hd+1));
        }
    }

    for(auto i:topNode)
    {
        ans.push_back(i.second);
    }

    return ans;
}

int main()
{
    Node * root = NULL;

    root = buildTree(root);
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1  

    cout << "Level order Traversal: " << endl;
    levelOrderTraversal(root);

    cout << endl;

    vector<int> ans = topView(root);

    cout << "Top View of the tree is: " << endl;
    for(int val: ans)
    {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}