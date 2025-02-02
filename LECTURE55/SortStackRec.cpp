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

void sortedInsert(Stack & st, int element)
{
    //base case
    if(st.empty())
    {
        st.push(element);
        return;
    }

    int num = st.peek();
    
    if(num >= element)
    {
        st.pop();
        sortedInsert(st, element);
        st.push(num);
        return;
    }
    else
    {
        st.push(element);
    }

}

void sortStack(Stack & st)
{
    //base case 
    if(st.empty())
    {
        return;
    }

    int num = st.peek();
    st.pop();

    sortStack(st);

    sortedInsert(st, num);

}

int main()
{
    Stack st(10);

    st.push(5);
    st.push(-2);
    st.push(9);
    st.push(-7);
    st.push(3);

    print(st);

    sortStack(st);

    print(st);

    return 0;
}