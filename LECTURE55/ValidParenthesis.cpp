#include<iostream>
using namespace std;

class Stack
{
    public:
    int size;
    int top;
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

bool isValidParenthesis(string expression)
{
    int length = expression.length();
    Stack * s = new Stack(length);
    
    // Stack s(length);
    // This automatically destroys s when the function returns, preventing memory leaks.

    for(int i = 0; i < length; i++)
    {
        char ch = expression[i];

        if(ch == '(' || ch == '[' || ch == '{')
        {
            s -> push(ch);
        }
        else
        {
            if(!s -> isEmpty())
            {
                char top = s -> peek();
                if((ch == ')' && top == '(') ||
                   (ch == ']' && top == '[') ||
                   (ch == '}' && top == '{'))
                {
                    s -> pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if(s -> isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string expression;
    cout << "Enter an expression with parentheses: ";
    cin >> expression;

    if(isValidParenthesis(expression))
    {
        cout << "Valid Parerntheses " << endl;
    }
    else
    {
        cout << "Invalid Parentheses " << endl;
    }

    return 0;
}