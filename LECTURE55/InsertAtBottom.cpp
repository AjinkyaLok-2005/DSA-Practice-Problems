#include<iostream>
using namespace std;

class Stack
{
    public:
    int * arr;
    int size;
    int top;

    Stack(int size)
    {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if(size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack OverFlow " << endl;
        }
    }

    void pop()
    {
        if(top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack UnderFlow " << endl;
        }
    }

    int peek()
    {
        if(top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is Empty " << endl;
            return -1;
        }
    }

    bool empty()
    {
        if(top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

void print(Stack &st)
{
    if(st.empty())
    {
        cout << "Stack is Empty " << endl;
        return;
    }

    cout << "Stack elements from top to bottom:- " << endl;

    for(int i = st.top; i >= 0; i--)
    {
        cout << st.arr[i] << " ";
    }
    cout << endl;
}

Stack insertAtBottom(Stack &st, int element)
{
    if(st.empty())
    {
        st.push(element);
        return st;
    }

    int num = st.peek();
    st.pop();

    insertAtBottom(st, element);

    st.push(num);

    return st;
}

int main()
{
    Stack st(10);

    st.push(7);
    st.push(1);
    st.push(4);
    st.push(5);

    print(st);

    Stack newSt = insertAtBottom(st, 9);

    print(newSt);

    return 0;
}