#include<iostream>
#include<queue>
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

    cout << "Enter data for inserting in left of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data for inserting in right of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

int height(node * node)
{
    //base case
    if(node == NULL)
    {
        return 0;
    }

    int left = height(node -> left);
    int right = height(node -> right);

    int ans = max(left, right) + 1;

    return ans;
}

int main()
{

    node * root = NULL;

    root = buildTree(root);
    //1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 9 8 -1 -1 -1 -1 

    int ans = height(root);
    cout << "height of the given tree is: " << ans << endl;

    return 0;
}