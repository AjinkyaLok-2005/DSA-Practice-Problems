//Deleting the Middle Node of the Linked List

#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;

    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtTail( Node *& head, Node *&tail, int d)
{
    Node* temp = new Node(d);
    
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail -> next = temp;
        tail = temp;
    } 
}

void print(Node* &head)
{
    if(head == NULL)
    {
        cout << "Linked List is empty " << endl;
    }
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next; 
    }
    cout << endl;
}

Node * deleteMiddle(Node * head)
{
    if(head == NULL)
    {
        return NULL;
    }

    if(head -> next == NULL)
    {
        return NULL;
    }

    Node * prev = NULL;
    Node * slow = head;
    Node * fast = head;

    while(fast != NULL && fast -> next != NULL)
    {
        prev = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    prev -> next = slow -> next;
    slow -> next = NULL;

    return head;
}

int main()
{
    Node * temp = new Node(1);
    Node * head = temp;
    Node * tail = temp;
    
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 6);

    print(head);

    Node * ans = deleteMiddle(head) ;

    print(ans);
    
    return 0;
}