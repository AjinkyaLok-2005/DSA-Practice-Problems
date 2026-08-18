#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
        {
            return NULL;
        }

        ListNode* p1 = headA;
        ListNode* p2 = headB;

        while(p1 != p2)
        {
            if(p1 == NULL)
            {
                p1 = headB;
            }
            else
            {
                p1 = p1 -> next;
            }

            if(p2 == NULL)
            {
                p2 = headA;
            }
            else
            {
                p2 = p2 -> next;
            }
        }

        return p1;
    }
};

// helper: build a plain list from an array, return head
ListNode* buildList(int arr[], int n)
{
    if (n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* tail = head;
    for (int i = 1; i < n; i++)
    {
        tail->next = new ListNode(arr[i]);
        tail = tail->next;
    }
    return tail; // returning tail so caller can attach intersection part; see main
}

int main()
{
    // ---- Example 1 ----
    // listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], intersect at node with val 8, skipA=2, skipB=3

    // build the shared/intersecting tail: 8 -> 4 -> 5
    ListNode* c1 = new ListNode(8);
    c1->next = new ListNode(4);
    c1->next->next = new ListNode(5);

    // build A's unique prefix: 4 -> 1 -> (c1...)
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = c1;

    // build B's unique prefix: 5 -> 6 -> 1 -> (c1...)
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = c1;

    Solution sol;
    ListNode* result = sol.getIntersectionNode(headA, headB);

    if (result != NULL)
        cout << "Intersected at '" << result->val << "'" << endl;
    else
        cout << "No intersection" << endl;

    // ---- Example 3: no intersection ----
    ListNode* headC = new ListNode(2);
    headC->next = new ListNode(6);
    headC->next->next = new ListNode(4);

    ListNode* headD = new ListNode(1);
    headD->next = new ListNode(5);

    ListNode* result2 = sol.getIntersectionNode(headC, headD);

    if (result2 != NULL)
        cout << "Intersected at '" << result2->val << "'" << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}