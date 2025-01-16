//REMOVING THE DUPLICATE ELEMENTS FROM THE SORTED LINKED LIST

#include<iostream>
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

    Node * temp = head;
    while(temp != NULL )
    {
        if(temp -> next != NULL && temp -> data == temp -> next -> data)
        {
            Node * curr = temp -> next;
            temp -> next = curr -> next;
            delete curr;
        }
        else
        {
            temp = temp -> next;
        }
    }

    return head;
}

int main()
{
    Node * node1 = new Node(4);
    Node * head = node1;

    insertAtHead(head, 3);
    insertAtHead(head, 3);
    insertAtHead(head, 3);
    insertAtHead(head, 2); 
    insertAtHead(head, 2); 
    insertAtHead(head, 1); 

    print(head);

    head = removeDuplicates(head);

    print(head);

    return 0;
}