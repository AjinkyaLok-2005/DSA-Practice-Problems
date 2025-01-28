#include<iostream>
using namespace std;

class Stack
{
    public:
    int top;
    int size;
    char * arr;

    Stack(int size)
    {
        this -> size = size;
        arr = new char[size];
        top = -1;
    }

    void push(char element)
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

    char peek()
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

    bool isEmpty()
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

int main()
{
    Stack st(10);

    string str = "ajinkya";

    for(int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        st.push(ch);
    }
    
    string ans = "";

    while(!st.isEmpty())
    {
        char ch  = st.peek();
        ans.push_back(ch);
        st.pop();
    }

    cout << endl;

    cout << "Original String is: " << str << endl;

    cout << endl;

    cout << "Answer is: " << ans << endl;

    cout << endl;

    return 0;
}