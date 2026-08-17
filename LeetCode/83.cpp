#include <iostream>
#include <vector>
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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* temp = head;

        while(temp != NULL && temp->next != NULL)
        {
            if(temp->val == temp->next->val)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }

        return head;
    }
};

// Function to create a linked list
ListNode* createList(vector<int>& nums)
{
    if(nums.empty())
        return NULL;

    ListNode* head = new ListNode(nums[0]);
    ListNode* temp = head;

    for(int i = 1; i < nums.size(); i++)
    {
        temp->next = new ListNode(nums[i]);
        temp = temp->next;
    }

    return head;
}

// Function to print a linked list
void printList(ListNode* head)
{
    ListNode* temp = head;

    while(temp != NULL)
    {
        cout << temp->val << " ";

        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    vector<int> nums = {1, 1, 2, 3, 3};

    // Create linked list
    ListNode* head = createList(nums);

    cout << "Original List: ";
    printList(head);

    // Create Solution object
    Solution obj;

    // Remove duplicates
    head = obj.deleteDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    return 0;
}