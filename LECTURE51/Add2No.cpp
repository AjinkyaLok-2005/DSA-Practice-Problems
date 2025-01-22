#include<iostream>
#include<vector>
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

void insertAtHead(Node * & head, int d)
{
    if(head == NULL)
    {
        Node * temp = new Node(d);
        head = temp;
        return;
    }

    Node *temp = new Node(d);
    temp->next = head;
    head = temp;

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

Node * reverse(Node * &head)
{
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

    return prev;
}

Node * insertAtTail(Node * &head, Node * &tail, int digit)
{
    Node * temp = new Node(digit);

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
    return tail;
}

Node * add(Node * &first, Node * &second)
{
    int carry = 0;

    Node * ansHead = NULL;
    Node * ansTail = NULL;

    while(first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if(first != NULL)
        {
            val1 = first -> data;
        }

        int val2 = 0;
        if(second != NULL)
        {
            val2 = second -> data;
        }

        int sum = carry + val1 + val2;

        int digit = sum % 10; //remainder

        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10; //quotient
        if(first != NULL)
        {
            first = first -> next;
        }
        if(second != NULL)
        {
            second = second -> next;
        }
    }
    return ansHead;
}

Node * addTwoLists(Node * first, Node * second)
{
    // reverse LL
    first = reverse(first);
    second = reverse(second);

    //add 2 LL

    Node * ans = add(first, second);

    ans = reverse(ans);

    return ans;
}

int main()
{
    Node * head1 = NULL;
    Node * head2 = NULL;

    // Insert elements into the linked list
    insertAtHead(head1, 4);
    insertAtHead(head1, 5);

    insertAtHead(head2, 6);
    insertAtHead(head2, 3);
    insertAtHead(head2, 2);

    // Print the linked list
    cout << "Linked List 1: ";
    print(head1);

    cout << "Linked List 2: ";
    print(head2);

    Node * ans = addTwoLists(head1, head2);

    print(ans);

    return 0;
}