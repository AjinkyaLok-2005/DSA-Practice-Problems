#include<iostream>
using namespace std;

class NStack
{
    public:
    int * arr;
    int * top;
    int * next;

    int n, s;

    int freespot;

    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        for(int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        for(int i = 0; i < s; i++)
        {
            next[i] = i+1;
        }

        next[s-1] = -1;

        freespot = 0;
    }

    bool push(int x, int m)
    {
        if(freespot == -1)
        {
            return false;
        }

        int index = freespot;

        freespot = next[index];

        arr[index] = x;

        next[index] = top[m-1];

        top[m-1] = index;

        return true;
    }

    int pop(int m)
    {
        if(top[m-1] == -1)
        {
            return -1;
        }

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};

int main()
{

    int numStacks = 3; // Number of stacks
    int stackSize = 10; // Total size of the array
    
    NStack stacks(numStacks, stackSize);
    
    // Pushing elements into different stacks
    stacks.push(10, 1);
    stacks.push(20, 1);
    stacks.push(30, 2);
    stacks.push(40, 3);
    stacks.push(50, 2);
    
    // Popping elements and printing
    cout << "Popped from stack 1: " << stacks.pop(1) << endl;
    cout << "Popped from stack 2: " << stacks.pop(2) << endl;
    cout << "Popped from stack 3: " << stacks.pop(3) << endl;
    cout << "Popped from stack 1: " << stacks.pop(1) << endl;
    cout << "Popped from stack 2: " << stacks.pop(2) << endl;

    return 0;
}