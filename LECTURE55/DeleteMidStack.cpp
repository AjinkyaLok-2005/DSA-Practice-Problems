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

class Stack
{
    public:
    Node * top;

    Stack()
    {
        this -> top = NULL;
    }

    void push(int data)
    {
        Node * temp = new Node(data);

        if(top == NULL)
        {
            top = temp;
        }
        else
        {
            temp -> next = top;
            top = temp;
        }
    }

    void pop()
    {
        if(top == NULL)
        {
            return;
        }
        else
        {
            Node * temp = top;
            top = top -> next;
            delete temp;
        }
    }

    int peek()
    {
        if(top != NULL)
        {
            return top -> data;
        }
        else
        {
            cout << "Stack is Empty " << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if(top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

void solve(Stack *&st, int count, int size)
//Access and modify the Stack object it points to (e.g., st->push() or st->pop()).

{
    //base case
    if(count == size/2)
    {
        st -> pop();//st->pop() should be used when calling member functions of a pointer to a class. 
        return;
    }

    int num = st -> peek();
    st -> pop();

    solve(st, count+1, size);

    st -> push(num);
}

void deleteMid(Stack *&st, int size)
{
    int count = 0;
    solve(st, count , size);
}

int main()
{
    Stack * st = new Stack();
    
    st -> push(1);
    st -> push(2);
    st -> push(3);
    st -> push(4);
    st -> push(5);

    int size = 5;

    deleteMid(st, size);

    cout << "Stack after deleting the middle element " << endl;
    while(!st -> isEmpty())
    {
        cout << st -> peek() << " ";
        st -> pop();
    }

    cout << endl;

    return 0;
}