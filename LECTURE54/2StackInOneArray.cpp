#include<iostream>
using namespace std;

class TwoStack
{
    public:
    int *arr;
    int top1;
    int top2;
    int size;
    
    TwoStack(int s)
    {
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    void push1(int num)
    {
        if(top2 - top1 > 1)
        {
            top1++;
            arr[top1] = num;
        }
        // else
        // {
        //     cout << "Stack OverFlow " << endl;
        // }
    }

    void push2(int num)
    {
        if(top2 - top1 > 1)
        {
            top2--;
            arr[top2] = num;
        }
        // else
        // {
        //     cout << "Stack OverFlow " << endl;
        // }
    }

    int pop1()
    {
        if(top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    int pop2()
    {
        if(top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }

};

int main()
{
    TwoStack st(10);
    st.push1(22);
    st.push1(23);
    st.push1(24);
    st.push1(25);

    st.push2(50);
    st.push2(49);
    st.push2(48);
    st.push2(47);
    st.push2(46);

    // Pop elements from Stack 1 and display them
    cout << "Popping from Stack 1: ";
    while (true)
    {
        int val = st.pop1();
        if (val == -1)
            break;
        cout << val << " ";
    }
    cout << endl;

    // Pop elements from Stack 2 and display them
    cout << "Popping from Stack 2: ";
    while (true)
    {
        int val = st.pop2();
        if (val == -1)
            break;
        cout << val << " ";
    }
    cout << endl;

    return 0;
}