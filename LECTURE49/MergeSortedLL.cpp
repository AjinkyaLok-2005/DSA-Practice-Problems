#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        return;
    }

    Node *temp = new Node(data);
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

Node *solve(Node *first, Node *second)
{
    // If only 1 element in the first list
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }

    Node *curr1 = first;
    Node *next1 = curr1->next;
    Node *curr2 = second;
    Node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            // Move curr1 and next1 forward
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }

    return first;
}

Node *sortTwoLists(Node *first, Node *second)
{
    if (first == NULL)
    {
        return second;
    }

    if (second == NULL)
    {
        return first;
    }

    if (first->data <= second->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}

int main()
{
    Node *list1 = NULL;
    Node *list2 = NULL;

    insertAtHead(list1, 10);
    insertAtHead(list1, 7);
    insertAtHead(list1, 5);
    insertAtHead(list1, 1);

    insertAtHead(list2, 9);
    insertAtHead(list2, 6);
    insertAtHead(list2, 3);
    insertAtHead(list2, 2);

    cout << "List 1: " << endl;
    print(list1);

    cout << "List 2: " << endl;
    print(list2);

    Node *sortedList = sortTwoLists(list1, list2);

    cout << "Merged Sorted List: " << endl;
    print(sortedList);

    return 0;
}
