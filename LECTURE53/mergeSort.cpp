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

void insertAtTail(Node * &head, Node * &tail, int data)
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

Node * findMid(Node * head)
{
    Node * slow = head;
    Node * fast = head -> next;

    while(fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow; 
}

Node * merge(Node * left, Node * right)
{
    if(left == NULL)
    {
        return right;
    }

    if(right == NULL)
    {
        return left;
    }

    Node * ans = new Node(-1); //dummy Node
    Node * temp = ans;

    //merge 2 sorted LL
    while(left != NULL && right != NULL)
    {
        if(left -> data < right -> data)
        {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else
        {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    while(left != NULL)
    {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }

    while(right != NULL)
    {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }

    ans = ans -> next;

    return ans;
}

Node * mergeSort(Node * head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }

    Node * mid = findMid(head);

    Node * left = head;
    Node * right = mid -> next;
    mid -> next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    Node * result = merge(left, right);

    return result;
}

int main()
{
    Node * node1 = new Node(3);
    Node * head = node1;
    Node * tail = node1;

    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 9);

    print(head);

    Node * ans = mergeSort(head);

    print(ans);
    return 0;
}