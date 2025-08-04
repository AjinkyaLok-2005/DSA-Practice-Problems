#include <limits.h>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    int row;
    int col;

    Node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

vector<int> smallestRange(vector<vector<int>>& nums) {
    int k = nums.size();  // Number of lists
    // Min-heap based on the Node's value
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    int mini = INT_MAX, maxi = INT_MIN;
    // Initialize heap with first element of each list
    for (int i = 0; i < k; i++) {
        if (nums[i].size() == 0) continue; // skip empty lists
        int element = nums[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Node(element, i, 0));
    }
    int start = mini, end = maxi;
    while (!minHeap.empty()) {
        Node* temp = minHeap.top();
        minHeap.pop();
        mini = temp->data;
        if (maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }
        // Move to next element in the same row if it exists
        if (temp->col + 1 < nums[temp->row].size()) {
            int nextVal = nums[temp->row][temp->col + 1];
            maxi = max(maxi, nextVal);
            minHeap.push(new Node(nextVal, temp->row, temp->col + 1));
        } else {
            // One of the lists is exhausted, can't continue
            break;
        }
    }
    return {start, end};
}

#include <iostream>

int main() {
    // Example input: each row is a sorted list
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };

    vector<int> result = smallestRange(nums);

    cout << "Smallest range is: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
