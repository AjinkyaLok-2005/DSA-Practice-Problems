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

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int findPosition(vector<int> &postorder, int target)
{
    for(int i = 0; i < postorder.size(); i++)
    {
        if(postorder[i] == target)
        {
            return i;
        }
    }
    return -1;
}

Node * build(vector<int> preorder, vector<int> postorder, int i1, int i2, int j1, int j2)
{
    //base case
    if(i1 > i2 || j1 > j2)
    {
        return NULL;
    }

    int value = preorder[i1];
    Node * root = new Node(value);

    if(i1 != i2)
    {
        int mid = findPosition(postorder, preorder[i1+1]);
        int left_size = mid - j1 + 1;
        root -> left = build(preorder, postorder, i1+1, i1+left_size, j1, mid);
        root -> right = build(preorder, postorder, i1+left_size+1, i2, mid+1, j2-1);
    }
    return root;
}

Node * constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    int n = preorder.size();

    int i1 = 0;
    int i2 = n-1;
    int j1 = 0;
    int j2 = n-1;
    
    Node * ans = build(preorder, postorder, i1, i2, j1, j2);

    return ans;
}

// MAIN FUNCTION
int main()
{
    vector<int> preorder = {1,2,4,5,3,6,7}; 
    vector<int> postorder = {4,5,2,6,7,3,1};

    Node *root = constructFromPrePost(preorder, postorder);

    cout << "The Original Tree is: \n";
    levelOrderTraversal(root);

    return 0;
}

