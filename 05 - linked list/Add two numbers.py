"""
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, 
and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Time complexity : O(max(m, n)) Assume that m and n represents the length of l1 and l2 respectively, the algorithm above iterates at most max(m, n) times.
Space complexity : O(max(m, n)). The length of the new list is at most max(m,n) + 1. 
"""


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # instantiate linked list which will hold the result
        head = temp = ListNode(None)
        carry = 0

        # while the linked lists aren't empty
        while l1 or l2:
            # assign carry over digit to sum and add list values to this
            sum_of_numbers = carry

            if l1 != None:
                # add to sum
                sum_of_numbers += l1.val
                # move pointer up
                l1 = l1.next

            if l2 != None:
                # add to sum
                sum_of_numbers += l2.val
                # move pointer up
                l2 = l2.next

            # split sum for single integer node in linked list
            prev_num = sum_of_numbers % 10
            carry = sum_of_numbers // 10

            # add node to linked list to store result
            temp.next = ListNode(prev_num)

            # move pointers up
            temp = temp.next

        # if at the end of the iteration, carry is still left over, add to resulting linked list
        if carry == 1:
            temp.next = ListNode(carry)

        # linked list instantiated with 0 as first element hence retun from the second el
        return head.next
