//Reversing the Linked List - Approach 2 (Recursion)

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

void reverse(Node * &head, Node * curr, Node * prev)
{
    Node * forward = NULL;

    //base case
    if(curr == NULL)
    {
        head = prev;
        return;
    }
    forward = curr -> next;
    reverse(head, forward, curr);
    curr -> next = prev;
}

Node * reverseLinkedList(Node * &head)
{
    Node * curr = head;
    Node * prev = NULL;
    reverse(head, curr, prev);
    return head;
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