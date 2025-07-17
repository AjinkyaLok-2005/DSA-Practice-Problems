#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data)
    {
        this -> data = data;
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

void insertAtTail(Node *&tail, int d)
{
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp; 
}

Node* mergeTwoLists(Node* list1, Node* list2) 
{
    Node dummy(-1);
    Node* tail = &dummy;
    while(list1 != NULL && list2 != NULL)
    {
        if(list1 -> data <= list2 -> data)
        {
            tail -> next = list1;
            list1 = list1 -> next;
            tail = tail -> next;
        }
        else
        {
            tail -> next = list2;
            list2 = list2 -> next;
            tail = tail -> next;
        }
    }
    while(list1 != NULL)
    {
        tail -> next = list1;
        tail = tail -> next;
        list1 = list1 -> next;
    }
    while(list2 != NULL)
    {
        tail -> next = list2;
        tail = tail -> next;
        list2 = list2 -> next;
    }
    return dummy.next;
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

int main()
{
    Node* list1 = new Node(1);
    Node* tail1 = list1;
    insertAtTail(tail1, 3);
    insertAtTail(tail1, 5);

    cout << "List 1: ";
    print(list1);

    Node* list2 = new Node(2);
    Node* tail2 = list2;
    insertAtTail(tail2, 4);
    insertAtTail(tail2, 6);

    cout << "List 2: ";
    print(list2);

    Node* mergedHead = mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    print(mergedHead);

    // delete mergedHead;

    return 0;
}