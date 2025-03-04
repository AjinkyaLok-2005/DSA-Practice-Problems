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

    cout << "Enter data for inserting in left of: " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data for inserting in right of: " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

vector<int> zigzagTraversal(Node * root)
{
    vector<int> result;
    if(root == NULL)
    {
        return result;
    }

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        // Level Processing
        for(int i = 0; i < size; i++)
        {
            Node * frontNode = q.front();
            q.pop();

            // Normal insert or reverse insert
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode -> data;

            if(frontNode -> left)
            {
                q.push(frontNode -> left);
            }

            if(frontNode -> right)
            {
                q.push(frontNode -> right);  // Fixed error here
            }            
        }

        // Change the direction
        leftToRight = !leftToRight;

        for(auto i: ans)
        {
            result.push_back(i);
        }
    }

    return result;
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
 
int main()
{
    Node * root = NULL;

    root = buildTree(root);

    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);

    //1 2 4 -1 -1 5 -1 -1 3 -1 -1 

    vector<int> ans = zigzagTraversal(root);

    cout << "Zig Zag traversal: ";
    for(int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
