//REMOVING THE DUPLICATE ELEMENTS FROM THE UNSORTED LINKED LIST

#include<iostream>
#include<unordered_set>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;

    //Constructor
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }

    //deconstructor
    ~Node()
    {
        if(this -> next != NULL)
        {
            this -> next = NULL;
            delete next;
        }
    }
};

void insertAtHead(Node * & head, int data)
{
    Node * temp = new Node (data);
    temp -> next = head;
    head = temp;
}

void print(Node * head)
{
    Node * temp = head;

    if(head == NULL)
    {
        cout << "Empty Linked List " << endl;
    }

    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

Node * removeDuplicates(Node * & head)
{
    if(head == NULL)
    {
        return NULL;
    }

    unordered_set<int> visited;

    Node * curr = head;
    Node * prev = NULL;

    while(curr != NULL)
    {
        if(visited.find(curr -> data) != visited.end())
        {
            prev -> next = curr -> next;
            delete curr;
            curr = prev -> next;
        }
        else
        {
            visited.insert(curr -> data);
            prev = curr;
            curr = curr -> next;
        }
    }

    return head;
}

int main()
{
    Node * node1 = new Node(2);
    Node * head = node1;

    insertAtHead(head, 2);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertAtHead(head, 2); 
    insertAtHead(head, 4); 

    print(head);

    Node * ans = removeDuplicates(head);
    print(ans);

    return 0;
}