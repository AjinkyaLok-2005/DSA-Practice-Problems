//Reverse Linked List Approach1
#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;

    //constructor
    Node(int d)
    {
        this -> data = d;
        this -> next = NULL;
    }
};

void insertAtHead(Node * &head, int d) //reference islye liya hai kyuki original LL me hi change ho
{   
    //create new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

Node * reverseLinkedList(Node * &head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }

    Node * curr = head;
    Node * prev = NULL;
    Node * forward = NULL; 

    while(curr != NULL)
    {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev; //New head of the reversed LL
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
    Node * Node1 = new Node(10); 
    Node * head = Node1;

    insertAtHead(head, 12);

    insertAtHead(head, 14);

    insertAtHead(head, 16);

    insertAtHead(head, 18);

    cout << "Original Linked List is " << endl;
    print(head);

    head = reverseLinkedList(head); //storing the new heaD

    cout << "Reversed Linked List is " << endl;
    print(head);

    return 0;
}