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

    void push(int element)
    {
        if(size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack OverFlow" << endl;
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
            cout << "Stack Empty " << endl;
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

    int getSize() 
    {  // Added size function
        return top + 1;
    }
};

bool knows(vector<vector<int>> & M, int a, int b, int n)
{
    if(M[a][b] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int findCelebrity(Stack & s, vector<vector<int>> & M, int n)
{
    for(int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while(s.getSize() > 1)
    {
        int a =  s.peek();
        s.pop();

        int b = s.peek();
        s.pop();

        if(knows(M, a, b, n))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }

    if(s.isEmpty()) return -1;

    int ans = s.peek();

    int zeroCount = 0;
    for(int i = 0; i < n; i++)
    {
        if(M[ans][i] == 0)
        {
            zeroCount++;
        }
    }
    if(zeroCount != n)
    {
        return -1;
    }

    int oneCount = 0;

    for(int i = 0; i < n; i++)
    {
        if(M[i][ans] == 1)
        {
            oneCount++;
        }
    }
    if(oneCount != n-1)
    {
        return -1;
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter number of people: ";
    cin >> n;

    vector<vector<int>> M(n, vector<int>(n));
    cout << "Enter the celebrity matrix (NxN values, 0 or 1):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }

    Stack s(n);
    int result = findCelebrity(s, M, n);

    if (result == -1) {
        cout << "No celebrity found." << endl;
    } else {
        cout << "Celebrity is at index: " << result << endl;
    }


    return 0;
}