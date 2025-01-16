//REMOVING THE DUPLICATE ELEMENTS FROM THE UNSORTED LINKED LIST

#include<iostream>
#include<map>
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
    Node * curr = head;
    while(curr != NULL)
    {
        Node * prev = curr;
        Node * temp = curr -> next;

        while(temp != NULL)
        {
            if(curr -> data == temp -> data)
            {
                prev -> next = temp -> next;
                delete temp;
                temp = prev -> next;
            }
            else
            {
                prev = temp;
                temp = temp -> next;
            }
        }
        curr = curr -> next;
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