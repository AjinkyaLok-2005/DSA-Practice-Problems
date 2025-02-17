#include <iostream>
#include <vector>
using namespace std;

class Stack
{
    public:
    vector<int> arr;
    int top;
    int size;

    Stack(int size)
    {
        if (size <= 0)
        {
            cout << "Invalid stack size!" << endl;
            exit(1);
        }
        this->size = size;
        arr.resize(size);
        top = -1;
    }

    void push(int element)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

class Queue
{
public:
    vector<int> arr;
    int front;
    int rear;

    Queue(int size)
    {
        arr.reserve(size); // Pre-allocate space but allow dynamic growth
        front = 0;
        rear = 0;
    }

    void enqueue(int element)
    {
        arr.push_back(element);
        rear++;
    }

    int dequeue()
    {
        if (front == rear)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else
        {
            int ans = arr[front];
            front++;
            return ans;
        }
    }

    int getFront()
    {
        if (front == rear)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool isEmpty()
    {
        return front == rear;
    }

    void print()
    {
        if (front == rear)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            cout << "Queue Elements: ";
            for (int i = front; i < rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

void modifyQueue(Queue &q, int k, int size)
{
    if (k > size)
    {
        cout << "Invalid k value!" << endl;
        return;
    }

    Stack s(k);

    // Step 1: Dequeue k elements and push onto the stack
    for (int i = 0; i < k; i++)
    {
        int val = q.dequeue();
        if (val != -1)
        {
            s.push(val);
        }
    }

    // Step 2: Pop from the stack and enqueue back to the queue
    while (!s.isEmpty())
    {
        int val = s.peek();
        s.pop();
        q.enqueue(val);
    }

    // Step 3: Move the remaining elements to the back
    int t = size - k;
    for (int i = 0; i < t; i++)
    {
        int val = q.dequeue();
        if (val != -1)
        {
            q.enqueue(val);
        }
    }
}

int main()
{
    Queue q(5);
    int size = 5;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.print();

    modifyQueue(q, 3, size);

    q.print();

    return 0;
}
