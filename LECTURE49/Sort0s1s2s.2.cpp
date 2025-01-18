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

    // ~Node()
    // {
    //     if(this -> next != NULL)
    //     {
    //         delete next;
    //         this -> next = NULL;
    //     }
    // }
};

void insertAtHead(Node * & head, int data)
{
    if(head == NULL)
    {
        Node * temp = new Node(data);
        head = temp;
    }

    Node * temp = new Node(data);

    temp -> next = head;
    head = temp;
}

void print(Node * head)
{
    if(head == NULL)
    {
        cout << "Empty List " << endl;
    }

    Node * temp = head;

    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtTail(Node * & tail, Node * curr)
{
    tail -> next = curr;
    tail = curr;
}

Node * sortList(Node * & head)
{
    Node * zeroHead = new Node(-1); 
    Node * zeroTail = zeroHead;
    Node * oneHead = new Node(-1);
    Node *  oneTail = oneHead;
    Node * twoHead = new Node(-1);
    Node *  twoTail = twoHead;

    Node * curr = head;

    //create seperate lists for 0 1 and 2
    while(curr != NULL)
    {
        int value = curr -> data;

        if(value == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2)
        {
            insertAtTail(twoTail, curr);
        }

        curr = curr -> next;
    }

    //merging 3 sublist

    //1s list is not empty
    if(oneHead -> next != NULL)
    {
        zeroTail-> next = oneHead -> next;
    }    
    else
    {
        //1s list is empty
        zeroTail -> next = twoHead -> next;
    }

    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    head = zeroHead -> next;

    //deleteing dummy Nodes 
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main()
{
    Node * node1 = new Node(2);
    Node * head = node1;

    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    insertAtHead(head, 1);

    print(head);

    head = sortList(head);

    print(head);

    return 0;
}