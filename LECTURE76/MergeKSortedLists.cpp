#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;

    Node(int d)
    {
        this -> data = d;
        this -> next = NULL;
    }
};

class compare
{
    public:
    bool operator()(Node* a, Node * b)
    {
        return a -> data > b -> data;
    }
};

void insertAtTail(Node *&tail, int d)
{
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp; 
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

Node * mergeKLists(vector<Node*> & lists)
{
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    int k = lists.size();

    if(k == 0)
    {
        return NULL;
    }

    for(int i = 0; i < k; i++)
    {
        if(lists[i] != NULL)
        {
            minHeap.push(lists[i]);
        }
    }

    Node * head = NULL;
    Node * tail = NULL;

    while(minHeap.size() != 0)
    {
        Node * top = minHeap.top();
        minHeap.pop();

        if(top -> next != NULL)
        {
            minHeap.push(top -> next);
        }

        if(head == NULL)
        {
            head = top;
            tail = top;
        }
        else
        {
            tail -> next = top;
            tail = top;
        }
    }
    return head;
}

int main()
{
    Node * list1 = new Node(1);
    Node * tail1 = list1;
    insertAtTail(tail1, 4);
    insertAtTail(tail1, 4);

    Node * list2 = new Node(1);
    Node * tail2 = list2;
    insertAtTail(tail2, 3);
    insertAtTail(tail2, 4);

    Node * list3 = new Node(2);
    Node * tail3 = list3;
    insertAtTail(tail3, 6);

    vector<Node*> lists = {list1, list2, list3};

    Node * mergedHead = mergeKLists(lists);

    print(mergedHead);

    return 0;
}