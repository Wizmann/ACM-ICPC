# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def pairSum(self, head):
        ns = []
        while head:
            ns.append(head.val)
            head = head.next
        return max(map(lambda (x, y): x + y, zip(ns, ns[::-1])))
