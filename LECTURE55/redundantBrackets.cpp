#include<iostream>
using namespace std;

class Stack
{
    public:
    char * arr;
    int size;
    int top;

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
            cout << " Stack OverFlow " << endl;
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

bool findRedundantBrackets(Stack & st, string &s)
{
    for(int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            if(ch == ')')
            {
                bool isRedundant = true;

                while(st.peek() != '(')
                {
                    char top = st.peek();

                    if(top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }

                if(isRedundant == true)
                {
                    return true;
                }
                st.pop();
            }
        }
    }

    return false;
}

int main()
{
    string s;
    cout << "Enter the Expression: ";
    cin >> s;

    Stack st(s.length());

    if(findRedundantBrackets(st, s))
    {
        cout << "Redundant brackets found " << endl;
    }
    else
    {
        cout << "No redundant brackets found " << endl;
    }

    return 0;
}