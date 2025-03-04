#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node * left;
    node * right;

    node(int d)
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node * buildTree(node * root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

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

pair <bool, int> isSumTreeFast(node * root)
{
    //base case
    if(root == NULL)
    {
        pair <bool, int> p = make_pair(true, 0);
        return p;
    }

    //leaf node
    if(root -> left == NULL && root -> right  == NULL)
    {
        pair<bool, int> p = make_pair(true, root -> data);
        return p;
    }

    pair<bool, int> leftAns = isSumTreeFast(root -> left);
    pair<bool, int> rightAns = isSumTreeFast(root -> right);

    //checking if sumtree or not
    bool left = leftAns.first;
    bool right = rightAns.first;

    bool condition = root -> data == leftAns.second + rightAns.second;

    pair<bool, int> ans;

    if(left && right && condition)
    {
        ans.first = true;
        ans.second = 2*root -> data;
    }
    else
    {
        ans.first = false;
    }
}

bool isSumTree(node * root)
{
    return isSumTreeFast(root).first;
}

int main()
{
    node * root = NULL;

    root = buildTree(root);

    bool ans = isSumTree(root);

    if(ans)
    {
        cout << "The given tree is a Sum Tree " << endl;
    }
    else
    {
        cout << "The given tree is not a Sum Tree " << endl;
    }

    return 0;
}