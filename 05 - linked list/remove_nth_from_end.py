# Given the head of a linked list, remove the nth node from the end of the list and return its head.
#
# Input: head = [1], n = 1
# Output: []
#
# Input: head = [1,2], n = 1
# Output: [1]

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # instantiate dummy pointing to head
        dummy = ListNode(0, head)
        fast = slow = dummy

        # put length n between fast and slow pointer
        for _ in range(n):
            fast = fast.next

        # iterate up until fastis at the last node
        while fast and fast.next:
            slow = slow.next
            fast = fast.next

        # bypass necessary node
        slow.next = slow.next.next

        return dummy.next