#include<iostream>
#include<vector>
#include<climits>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach 1
class Solution {
public:
    int pairSum(ListNode* head) {
        int maxSum = INT_MIN;

        ListNode* temp = head;

        vector<int> arr;

        while(temp != NULL)
        {
            arr.push_back(temp -> val);
            temp = temp -> next;
        }

        int n = arr.size()-1; 

        for(int i = 0; i <= n/2; i++)
        {
            int sum = arr[i] + arr[n-i];
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};

// Approach 2 - Using Stack
class Solution{
public:
    int pairSum(ListNode* head)
    {
        stack<int> st;
        ListNode* curr = head;
        while(curr != NULL)
        {
            st.push(curr -> val);
            curr = curr -> next;
        }
        int n = st.size();
        curr = head;
        int count = 1;
        int result = 0;
        while(count <= n/2)
        {
            result = max(result, curr -> val + st.top());
            curr = curr -> next;
            st.pop();
            count ++;
        }
        return result;
    }
};

// Approach 3 - Using Fast and Slow Pointer
class Solution {
public:
    int pairSum(ListNode* head) {
        //Find Mid
        ListNode * slow = head;
        ListNode * fast = head;

        while(fast != NULL && fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* mid = slow;

        //Reverse 2nd half
        ListNode * prev = NULL;
        ListNode * next = NULL;

        while(mid != NULL)
        {
            next = mid -> next;
            mid -> next = prev;
            prev = mid;
            mid = next;
        }

        //Find Max
        int result = 0;

        ListNode* curr = head;

        while(prev != NULL)
        {
            result = max(result, curr -> val + prev -> val); //prev will be pointing at the middle node after reversing
            curr = curr -> next;
            prev = prev -> next; 
        }

        return result;
    }
};

int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution obj;
    int result = obj.pairSum(head);

    cout << "Maximum Twin Sum: " << result << endl; // Output: 5

    return 0;
}

