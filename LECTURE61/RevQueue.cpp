#include<iostream>
#include<stack>
#include<queue>
using namespace std;

queue<int> rev(queue<int> q)
{
    stack<int> s;

    while(!q.empty())
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while(!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
}

void print(queue<int> q)
{
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(15);
    q.push(25);
    q.push(35);
    q.push(45);
    q.push(55);

    cout << "Qriginal Queue: " << endl;
    print(q);

    q = rev(q);

    cout << endl;

    cout << "Reversed Queue: " << endl;
    print(q);

    return 0;
}