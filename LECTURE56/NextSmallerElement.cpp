#include<iostream>
#include<vector>
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

vector<int> nextSmallerElement(Stack & s, vector<int> & arr, int n)
{
    s.push(-1);
    vector<int> ans(n);

    for(int i = n-1; i >= 0; i--)
    {
        int curr = arr[i];
        while(s.peek() >= curr)
        {
            s.pop();
        }
        ans[i] = s.peek();
        s.push(curr);
    }
    return ans;
}

void printVector(const vector<int> &vec) 
{
    for (int val : vec) 
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {4, 5, 2, 10, 8};
    int n = arr.size();

    Stack s(n);
    vector<int> result = nextSmallerElement(s, arr, n);

    cout << "Next Smaller Elements are: ";
    printVector(result);

    return 0;
}