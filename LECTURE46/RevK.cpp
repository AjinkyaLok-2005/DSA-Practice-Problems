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

void insertAtHead(Node * & head, int d)
{
    Node * temp = new Node(d);

    temp -> next = head;
    head = temp;
}

Node * reverseK(Node * & head, int k)
{
        //base case
    if(head == NULL)
    {
        return NULL;
    }

    //reverse first k nodes
    Node * next = NULL;
    Node * curr = head;
    Node * prev = NULL;

    int count = 0;

    while(curr != NULL && count < k)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    //recursion 
    if(next != NULL)
    {
        head -> next = reverseK(next, k);
    }

    return prev;
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
    cout << "Original Linked List" << endl;

    head = reverseK(head, 2);

    cout << "Reversed Linked List in groups of K: " << endl;

    print(head);

    return 0;
}