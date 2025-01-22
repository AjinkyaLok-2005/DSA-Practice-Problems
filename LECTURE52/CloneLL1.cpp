#include<iostream>
#include<unordered_map>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;
    Node * random;

    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtTail(Node * & head, Node * & tail, int data)
{
    Node * temp = new Node(data);

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

void print(Node *head)
{
    if (head == NULL)
    {
        cout << "Empty List" << endl;
        return; // Return if the list is empty
    }

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node * copyList(Node * &head)
{
    Node * cloneHead = NULL;
    Node * cloneTail = NULL;

    Node * temp = head;

    while(temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp -> data);
        temp = temp -> next;
    }

    //Create a Map
    unordered_map<Node*, Node*> oldToNewNode;

    Node * originalNode = head;
    Node * cloneNode = cloneHead;

    while(originalNode != NULL)
    {
        oldToNewNode[originalNode] = cloneNode;
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }

    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL)
    {
        cloneNode -> random = oldToNewNode[originalNode -> random];
        originalNode = originalNode -> next;
        cloneNode = cloneNode -> next;
    }

    return cloneHead;

}

int main()
{
    Node * temp = new Node(1);

    Node * head = temp;
    Node * tail = temp;

    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);

    head->random = head->next->next;           // Node 1's RANDOM points to Node 3
    head->next->random = head;                 // Node 2's RANDOM points to Node 1
    head->next->next->random = head->next->next->next->next; // Node 3's RANDOM points to Node 5
    head->next->next->next->random = head->next->next;       // Node 4's RANDOM points to Node 3
    head->next->next->next->next->random = head->next;       // Node 5's RANDOM points to Node 2


    cout << "Original Linked List " << endl;
    print(head);

    cout << "Original List Random Pointer Mappings:" << endl;

    Node * temp1 = head;
    while(temp1 != NULL)
    {
        cout << temp1 -> data << " -> random : ";
        if(temp1 -> random)
        {
            cout << temp1 -> random -> data << endl;
        }
        else
        {
            cout << temp1 -> next;
        }
        
        temp1 = temp1 -> next;

    }

    cout << endl;

    Node * ans = copyList(head);
    cout << "Clone Linked List " << endl;
    print(ans);

    cout << "Cloned List Random Pointer Mappings:" << endl;
    Node* temp2 = ans;
    while (temp2 != NULL)
    {
        cout << "Node " << temp2->data << " -> Random Points to: ";

        if (temp2->random)
        {
            cout << temp2->random->data << endl;
        }
        else
        {
            cout << "NULL" << endl;
        }
            
        temp2 = temp2->next;
        
    }

    return 0;
}