#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head -> next == NULL)
        {
            return NULL;
        }

        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * prev = NULL;

        while(fast != NULL && fast -> next != NULL)
        {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode * mid = slow;

        prev -> next = mid -> next;

        return head;
    }
};

int main()
{  
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    ListNode* result = obj.deleteMiddle(head);

    // Print the modified linked list
    ListNode* temp = result;
    while(temp != NULL)
    {
        cout << temp -> val << " ";
        temp = temp -> next;
    }
    cout << endl;

    return 0;
}