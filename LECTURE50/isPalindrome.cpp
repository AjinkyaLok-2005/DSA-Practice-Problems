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


bool checkPalindrome(vector<int> arr)
{
    int n = arr.size();
    int s = 0;
    int e = n-1;

    while(s <= e)
    {
        if(arr[s] != arr[e])
        {
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}

bool isPalindrome(Node * head)
{
    vector<int> arr;

    Node * temp = head;
    while(temp != NULL)
    {
        arr.push_back(temp -> data);
        temp = temp -> next;
    }

    return checkPalindrome(arr);
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