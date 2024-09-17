#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

ListNode* modifiedList(vector<int>& nums, ListNode* head) 
{
    ListNode* temp = new ListNode(0);
    temp -> next = head;
    ListNode* prev = temp;  
    ListNode* curr = head;
    unordered_set<int> numsSet(nums.begin(), nums.end());
    while(curr != NULL)
    {
        if(numsSet.count(curr -> val))
        {
            prev -> next = curr -> next;
        }
        else
        {
            prev = prev -> next;
        }
        curr = curr -> next;
    }
    return temp -> next;  
}

int main()
{
    // Create the linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create the nums array
    vector<int> nums = {1, 2, 3};

    // Call the modifiedList function
    ListNode* modifiedHead = modifiedList(nums, head);

    // Print the modified linked list
    while (modifiedHead != nullptr) {
        cout << modifiedHead->val << " ";
        modifiedHead = modifiedHead->next;
    }
    cout << endl;
    
    return 0;
}