#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* curr;

    void solve(ListNode* head)
    {
        if(head == NULL)
        {
            return;
        }

        solve(head->next);

        ListNode* temp = curr->next;

        if(curr->next == NULL)
        {
            return;
        }
        else if(head == curr)
        {
            head->next = NULL;
            return;
        }

        curr->next = head;
        head->next = (temp == head) ? NULL : temp;

        curr = temp;
    }

    void reorderList(ListNode* head)
    {
        curr = head;
        solve(head);
    }
};

int main()
{
    // Create linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";

    ListNode* temp = head;
    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;

    // Reorder the list
    Solution obj;
    obj.reorderList(head);

    cout << "Reordered list: ";

    temp = head;
    while(temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;

    return 0;
}