#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top())
            minSt.push(val);
    }
    
    void pop() {
        if (st.top() == minSt.top())
            minSt.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

int main() {
    MinStack obj;

    obj.push(-2);
    obj.push(0);
    obj.push(-3);

    cout << obj.getMin() << endl; // -3
    obj.pop();
    cout << obj.top() << endl;    // 0
    cout << obj.getMin() << endl; // -2

    return 0;
}
