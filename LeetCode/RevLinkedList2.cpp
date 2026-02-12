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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == NULL || left == right)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* temp = dummy;
        
        for(int i = 1; i < left; i++)
        {
            temp = temp->next;
        }

        ListNode* curr = temp->next;
        ListNode* leftNode = curr;
        ListNode* prev = NULL;

        for(int i = 0; i <= right-left; i++)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        temp->next = prev;
        leftNode->next = curr;

        return dummy->next;   
    }
};

void printList(ListNode* head)
{
    while(head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


int main()
{
    // Create linked list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.reverseBetween(head, 2, 4);

    cout << "After Reversing (2 to 4): ";
    printList(head);

    return 0;
}

