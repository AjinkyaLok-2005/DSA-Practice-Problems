#include<iostream>
#include<queue>
#include<stack>
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

Node * InsertIntoBST(Node * root, int d)
{
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if(d > root -> data)
    {
        root -> right = InsertIntoBST(root -> right, d);
    }
    else
    {
        root -> left = InsertIntoBST(root -> left, d); 
    }
    return root;
}

void takeInput(Node * & root)
{
    int data;
    cin >> data;

    while(data != -1)
    {
        root = InsertIntoBST(root, data);
        cin >> data;
    }
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

void inorder(Node *root, vector<int> & in)
{
    //base case
    if(root == NULL)
    {
        return;
    }

    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

vector<int> mergeArray(vector<int> & a, vector<int> & b)
{
    vector<int> ans(a.size() + b.size());

    int i = 0;
    int j = 0;
    int k = 0;

    while(i < a.size() && j < b.size())
    {
        if(a[i] <= b[j])
        {
            ans[k++] = a[i];
            i++;
        }
        else
        {
            ans[k++] = b[j];
            j++;
        }
    }

    while(i < a.size())
    {
        ans[k++] = a[i];
        i++;
    }
    while(j < b.size())
    {
        ans[k++] = b[j];
        j++;
    }

    return ans;
}

Node * inorderToBST(int s, int e, vector<int> & in)
{
    //base case
    if(s > e)
    {
        return NULL;
    }

    int mid = (s+e)/2;
    Node * root = new Node(in[mid]);
    root ->left = inorderToBST(s, mid-1, in);
    root -> right = inorderToBST(mid+1, e, in);

    return root;
}

Node* mergeBST(Node *root1, Node *root2)
{
    // Write your code here.

    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    vector<int> mergedArray = mergeArray(bst1, bst2);

    int s = 0;
    int e = mergedArray.size() - 1;

    return inorderToBST(s, e, mergedArray);
}

Node * buildTree(Node * root)
{
    cout << "Enter the data : " << endl;
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

int main()
{
    Node *root1 = NULL;
    Node *root2 = NULL;

    cout << "Enter data to create Tree 1: " << endl;
    takeInput(root1);

    cout << "Enter data to create Tree 2: " << endl;
    takeInput(root2);

    cout << "Printing BST 1:" << endl;
    levelOrderTraversal(root1);

    cout << "Printing BST 2:" << endl;
    levelOrderTraversal(root2);

    Node *ans = mergeBST(root1, root2);

    cout << "\nPrinting the Balanced Merged BST: " << endl;
    levelOrderTraversal(ans);

    return 0;
}
