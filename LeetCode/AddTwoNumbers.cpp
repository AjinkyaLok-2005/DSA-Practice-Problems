#include <iostream>
using namespace std;

// Definition for singly-linked list node
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode() {
        val = 0;
        next = NULL;
    }

    ListNode(int x) {
        val = x;
        next = NULL;
    }

    ListNode(int x, ListNode* nextNode) {
        val = x;
        next = nextNode;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int carry = 0;

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (temp1 != NULL || temp2 != NULL || carry != 0) {
            int x = 0, y = 0;

            if (temp1 != NULL)
                x = temp1->val;

            if (temp2 != NULL)
                y = temp2->val;

            int sum = x + y + carry;
            int digit = sum % 10;
            carry = sum / 10;

            current->next = new ListNode(digit);
            current = current->next;

            if (temp1 != NULL)
                temp1 = temp1->next;

            if (temp2 != NULL)
                temp2 = temp2->next;
        }

        return dummy->next;
    }
};

int main() {
    // First number: 342 (stored as 2 -> 4 -> 3)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Second number: 465 (stored as 5 -> 6 -> 4)
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    // Print result: should be 7 -> 0 -> 8 (807)
    cout << "Result: ";
    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}
