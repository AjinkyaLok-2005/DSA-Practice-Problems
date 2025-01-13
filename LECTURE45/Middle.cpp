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

Node * getMiddle(Node * & head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }

    Node * slow = head;
    Node * fast = head -> next;

    while(fast != NULL)
    {
        fast = fast -> next;
        if(fast != NULL)
        {
            fast = fast -> next;
        }
        
        slow = slow -> next;
    }

    return slow;
}

Node * findMiddle(Node * head)
{
    return getMiddle(head);
}

void insertAtHead(Node * & head, int d)
{
    Node * temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void print(Node * head)
{
    Node * temp = head;

    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{

    Node * node1 = new Node(10);
    Node * head = node1;
    Node * Middle = NULL;

    insertAtHead(head, 12);
    insertAtHead(head, 14);
    insertAtHead(head, 16);
    insertAtHead(head, 18);
    insertAtHead(head, 20);

    print(head);

    Middle = findMiddle(head);

    cout << "Middle Node is " << Middle -> data << endl;

    return 0;
}