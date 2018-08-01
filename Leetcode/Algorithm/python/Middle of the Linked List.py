# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def middleNode(self, head):
        p, q = head, head
        while p and q:
            if q and q.next:
                q = q.next
            else:
                break
            if q and q.next:
                q = q.next
            p = p.next
        return p
        
