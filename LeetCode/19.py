from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverse(self, head):
        if head is None or head.next is None:
            return head

        prev = None
        curr = head
        forward = None

        while curr != None:
            forward = curr.next
            curr.next = prev
            prev = curr
            curr = forward

        return prev

    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        head = self.reverse(head)

        if n == 1:
            head = head.next
        else:
            count = 1
            temp = head

            while count != n - 1:
                temp = temp.next
                count += 1

            temp.next = temp.next.next

        head = self.reverse(head)

        return head


# ---------- Helper functions for testing ----------

def build_list(values):
    """Builds a linked list from a Python list and returns its head."""
    dummy = ListNode()
    curr = dummy
    for v in values:
        curr.next = ListNode(v)
        curr = curr.next
    return dummy.next


def list_to_array(head):
    """Converts a linked list back into a Python list for easy printing/comparison."""
    result = []
    while head:
        result.append(head.val)
        head = head.next
    return result


# ---------- Main guard with test cases ----------

if __name__ == "__main__":
    solution = Solution()

    test_cases = [
        ([1, 2, 3, 4, 5], 2, [1, 2, 3, 5]),
        ([1], 1, []),
        ([1, 2], 1, [1]),
        ([1, 2], 2, [2]),
        ([1, 2, 3, 4, 5], 5, [2, 3, 4, 5]),
    ]

    for values, n, expected in test_cases:
        head = build_list(values)
        result_head = solution.removeNthFromEnd(head, n)
        result = list_to_array(result_head)

        status = "PASS" if result == expected else "FAIL"
        print(f"[{status}] input={values}, n={n} -> got={result}, expected={expected}")