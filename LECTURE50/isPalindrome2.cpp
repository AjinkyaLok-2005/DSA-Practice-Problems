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

Node * getMiddle(Node * & head)
{
    Node * slow = head;
    Node * fast = head -> next;

    while(fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    return slow;
}

Node * reverse(Node * head)
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

bool isPalindrome(Node * &head)
{
    if(head == NULL || head -> next == NULL)
    {
        return true;
    }

    //step 1 -> find middle
    Node * middle = getMiddle(head);

    //step 2 -> reverse list after middle
    Node * temp = middle -> next;
    middle -> next = reverse(temp);

    //step 3 -> compare
    Node * head1 = head;
    Node * head2 = middle -> next;

    while(head2 != NULL)
    {
        if(head1 -> data != head2 -> data)
        {
            return false;
        }
        head1 = head1 -> next;
        head2  = head2 -> next;
    }

    //step 4 -> repeat step 2
    temp = middle -> next;
    middle -> next = reverse(temp);

    return true;

}

int main()
{
    Node *head = NULL;

    // Insert elements into the linked list
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    // Print the linked list
    cout << "Linked List: ";
    print(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head))
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}