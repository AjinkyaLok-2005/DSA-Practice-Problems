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

void inorder(Node * root, vector<int> & in)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root -> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

bool twoSumInBST(Node* root, int target) {
	//Write your code here
    vector<int> inorderVal;

    int i = 0;
    int j = inorderVal.size() - 1;

    while(i < j)
    {
        int sum = inorderVal[i] + inorderVal[j];
        if(sum == target)
        {
            return true;
        }
        else if(sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
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
    Node * root = NULL;

    cout << "Enter data to create Tree: " << endl;
    takeInput(root);

    // root = buildTree(root);

    cout << "Printing the BST: " << endl;
    levelOrderTraversal(root);

    bool ans = twoSumInBST(root, 20);

    if(ans)
    {
        cout << "There exists a Pair of Node " << endl;
    }    
    else
    {
        cout << "There does not exist a pair of Node " << endl; 
    }
    
    return 0;
}