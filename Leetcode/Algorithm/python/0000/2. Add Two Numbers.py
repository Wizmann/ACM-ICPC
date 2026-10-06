# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        l3 = ListNode(-1)
        ptr = l3
        
        g = 0
        while l1 or l2 or g:
            a = l1.val if l1 else 0
            b = l2.val if l2 else 0
            c = a + b + g
            
            ptr.next = ListNode(c % 10)
            g = c / 10
            ptr = ptr.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        
        return l3.next
