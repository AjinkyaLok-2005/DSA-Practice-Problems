#include<iostream>
#include<map>
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

void insertAtPosition(Node* & head, Node* & tail, int position, int d)
{
    //insert at start
    if(position == 1)
    {
        insertAtHead(head, d);
        return ;
    }

    Node * temp = head;
    int cnt = 1;

    while(cnt < position-1)
    {
        temp = temp -> next;
        cnt++;
    }

    //insert at tail
    if(temp -> next == NULL)
    {
        insertAtTail(tail, d);
        return ;
    }

    //creating a node for d

    Node * nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
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


bool isCircularList(Node * head)
{
    //empty List   
    if(head == NULL)
    {
        return true;
    }

    Node * temp = head -> next;
    while(temp != NULL && temp != head)
    {
        temp = temp -> next;
    }
 
    if(temp == head)
    {
        return true;
    }

    return false;
}

bool detectLoop(Node * head)
{
    if(head == NULL)
    {
        return false;
    }

    map<Node*, bool> visited;

    Node * temp = head;

    while(temp != NULL)
    {
        //checking if already visited
        if(visited[temp] == true)
        {
            cout << "Present on element " << temp -> data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}

int main()
{
    //created a new node
    Node* node1 = new Node(10);

    //head pointeed to node1
    Node* head = node1;
    Node* tail  = node1;
    print(head);

    insertAtTail(tail, 12);
    // print(head);

    insertAtTail(tail, 15);
    // print(head);

    insertAtPosition(head, tail, 4, 22);
    // print(head);

    // cout << "head " << head -> data << endl;  
    // cout << "tail " << tail -> data << endl;  

    // deleteNode(3, head, tail);
    print(head);
    
    tail -> next = head -> next;

    // cout << "head " << head -> data << endl;  
    // cout << "tail " << tail -> data << endl; 

    if(detectLoop(head))
    {
        cout << "Cycle is present " << endl;
    }
    else
    {
        cout << "No Cycle " << endl;
    }

    // if(isCircularList(tail))
    // {
    //     cout << "Linked List is Circular " << endl;
    // }
    // else
    // {
    //     cout << "Linked List is not Circular " << endl;
    // }
 

    return 0;
}