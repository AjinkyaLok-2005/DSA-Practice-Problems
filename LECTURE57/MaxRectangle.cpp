#include<iostream>
#include<vector>
#include<climits>
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
            return -1;
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

vector<int> nextSmallerElement(int * arr, int n) {
    Stack s(n);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!s.isEmpty() && (s.peek() == -1 || arr[s.peek()] >= arr[i])) {
            s.pop();
        }
        ans[i] = s.isEmpty() ? n : s.peek();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(int * arr, int n) {
    Stack s(n);
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        while (!s.isEmpty() && (s.peek() == -1 || arr[s.peek()] >= arr[i])) {
            s.pop();
        }
        ans[i] = s.isEmpty() ? -1 : s.peek();
        s.push(i);
    }
    return ans;
}

int largestRectangularArea(int * heights, int n) {
    vector<int> next = nextSmallerElement(heights, n);
    vector<int> prev = prevSmallerElement(heights, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++) {
        int l = heights[i];
        int b = next[i] - prev[i] - 1;
        area = max(area, l * b);
    }
    return area;
}

int maxArea(vector<vector<int>>& M, int n, int m)
{
    int area = largestRectangularArea(M[0].data(), m);

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(M[i][j] != 0)
                M[i][j] += M[i-1][j];
        }
        area = max(area, largestRectangularArea(M[i].data(), m));
    }
    return area;
}

int main()
{
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;
    vector<vector<int>> M(n, vector<int>(m));
    
    cout << "Enter the matrix elements (0 or 1):\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> M[i][j];
        }
    }

    int result = maxArea(M, n, m);
    cout << "Largest rectangular area of 1s is: " << result << endl;
    return 0;
}
