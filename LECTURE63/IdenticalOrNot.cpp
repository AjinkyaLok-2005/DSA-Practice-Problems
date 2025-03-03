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

bool isIdentical(node * r1, node * r2)
{
    //base case
    if(r1 == NULL && r2 == NULL)
    {
        return true;
    }

    if(r1 == NULL && r2 != NULL)
    {
        return false;
    }

    if(r1 != NULL && r2 == NULL)
    {
        return false;
    }

    bool left = isIdentical(r1 -> left, r2 -> left);
    bool right = isIdentical(r1 -> right, r2 -> right) ;

    bool value = r1 -> data == r2 -> data;

    if(left && right && value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    node * r1 = NULL;
    node * r2 = NULL;

    cout << "First Tree " << endl;
    r1 = buildTree(r1);

    cout << endl;

    cout << "Second Tree " << endl;
    r2 = buildTree(r2);

    cout << endl;

    bool ans = isIdentical(r1, r2);

    if(ans)
    {
        cout << "Both the trees are identical " << endl;
    }
    else
    {
        cout << "Trees are not identical " << endl;
    }

    return 0;
}