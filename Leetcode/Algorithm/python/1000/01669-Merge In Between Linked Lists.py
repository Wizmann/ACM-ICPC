# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeInBetween(self, list1, a, b, list2):
        head = list1
        p1 = head
        for i in xrange(a - 1):
            p1 = p1.next
        p2 = head
        for i in xrange(b + 1):
            p2 = p2.next
        p3 = list2
        while p3.next:
            p3 = p3.next
        p1.next = list2
        p3.next = p2
        return head
        
