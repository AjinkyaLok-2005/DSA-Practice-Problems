#include <iostream>
#include <vector>
#include <climits>  // For INT_MIN
using namespace std;

class Stack {
public:
    int* arr;
    int size;
    int top;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {  // Changed from char to int
        if (size - top > 1) {
            top++;
            arr[top] = element;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek() {  // Changed return type to int
        if (top >= 0) {
            return arr[top];
        } else {
            return -1;
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

vector<int> nextSmallerElement(vector<int>& arr, int n) {
    Stack s(n);
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        int curr = arr[i];
        while (s.peek() != -1 && arr[s.peek()] >= curr) {
            s.pop();
        }
        ans[i] = s.peek();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int>& arr, int n) {
    Stack s(n);
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        int curr = arr[i];
        while (s.peek() != -1 && arr[s.peek()] >= curr) {
            s.pop();
        }
        ans[i] = s.peek();
        s.push(i);
    }
    return ans;
}

int largestRectangularArea(vector<int>& heights) {
    int n = heights.size();

    vector<int> next = nextSmallerElement(heights, n);
    vector<int> prev = prevSmallerElement(heights, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++) {
        int l = heights[i];

        if (next[i] == -1) {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;

        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

void printHistogram(vector<int>& heights) {
    cout << "Histogram Heights: ";
    for (int h : heights) {
        cout << h << " ";
    }
    cout << endl;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    printHistogram(heights);
    cout << "Largest Rectangular Area: " << largestRectangularArea(heights) << endl;
    return 0;
}
