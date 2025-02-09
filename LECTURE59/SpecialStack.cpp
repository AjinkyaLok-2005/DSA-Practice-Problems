#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;

class SpecialStack
{
    stack<int> s;
    int mini = INT_MAX;

    public:
    void push(int data)
    {
        if(s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if(data < mini)
            {
                s.push(2 * data - mini);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }

    int pop()
    {
        if(s.empty())
        {
            return -1;
        }
        
        int curr = s.top();
        s.pop();
        if(curr > mini)
        {
            return curr;
        }
        else
        {
            int prevMin = mini;
            int val = 2 * mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top()
    {
        if(s.empty())
        {
            return -1;
        }

        int curr = s.top();
        if(curr < mini)
        {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    bool isEmpty()
    {
        return s.empty();
    }

    int getMin()
    {
        if(s.empty())
        {
            return -1;
        }

        return mini;
    }
};

int main()
{
    SpecialStack s;

    s.push(5);
    s.push(2);
    s.push(8);
    s.push(1);
    s.push(10);

    cout << "Minimum Element " << s.getMin() << endl;

    cout << "Top Element " << s.top() << endl; 
    cout << "Popped Element " << s.top() << endl;

    cout << "Top Element " << s.top() << endl;
    cout << "Popped Element " << s.pop() << endl;

    cout << "Minimum Element " << s.getMin() << endl;

    cout << "Popped Element " << s.pop() << endl;
    cout << "Popped Element " << s.pop() << endl;
    cout << "Popped Element " << s.pop() << endl;

    cout << "Is Stack Empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}