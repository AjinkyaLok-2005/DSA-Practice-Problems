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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(int arr[], int n) {
    if (n == 0) return NULL;
    
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    
    return head;
}

// Helper function to create a cycle in the linked list
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return; // No cycle
    
    ListNode* cycleNode = NULL;
    ListNode* current = head;
    int index = 0;
    
    // Find the node where cycle should start
    while (current->next != NULL) {
        if (index == pos) {
            cycleNode = current;
        }
        current = current->next;
        index++;
    }
    
    // Create cycle by pointing last node to the cycle node
    if (cycleNode != NULL) {
        current->next = cycleNode;
    }
}

// Helper function to print the result
void printResult(bool result, int testCase) {
    cout << "Test case " << testCase << ": ";
    if (result) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle found." << endl;
    }
}

int main() {
    Solution solution;
    
    // Test case 1: Linked list with cycle
    cout << "=== Test Case 1: Linked list with cycle ===" << endl;
    int arr1[] = {3, 2, 0, -4};
    ListNode* head1 = createLinkedList(arr1, 4);
    createCycle(head1, 1); // Create cycle at position 1 (0-indexed)
    printResult(solution.hasCycle(head1), 1);
    
    // Test case 2: Linked list without cycle
    cout << "\n=== Test Case 2: Linked list without cycle ===" << endl;
    int arr2[] = {1, 2, 3, 4, 5};
    ListNode* head2 = createLinkedList(arr2, 5);
    createCycle(head2, -1); // No cycle
    printResult(solution.hasCycle(head2), 2);
    
    // Test case 3: Single node with cycle (points to itself)
    cout << "\n=== Test Case 3: Single node with cycle ===" << endl;
    ListNode* head3 = new ListNode(1);
    head3->next = head3; // Create self-cycle
    printResult(solution.hasCycle(head3), 3);
    
    // Test case 4: Single node without cycle
    cout << "\n=== Test Case 4: Single node without cycle ===" << endl;
    ListNode* head4 = new ListNode(1);
    head4->next = NULL;
    printResult(solution.hasCycle(head4), 4);
    
    // Test case 5: Empty list
    cout << "\n=== Test Case 5: Empty list ===" << endl;
    ListNode* head5 = NULL;
    printResult(solution.hasCycle(head5), 5);
    
    // Test case 6: Two nodes with cycle
    cout << "\n=== Test Case 6: Two nodes with cycle ===" << endl;
    int arr6[] = {1, 2};
    ListNode* head6 = createLinkedList(arr6, 2);
    createCycle(head6, 0); // Create cycle at position 0
    printResult(solution.hasCycle(head6), 6);
    
    // Clean up memory (for non-cyclic lists)
    // Note: For cyclic lists, we'd need a more complex cleanup
    // For simplicity, we're not cleaning up cyclic lists here
    
    return 0;
}