# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def FindKthToTail(self, head, k):
        cur = head
        n = 0
        while cur:
            n += 1
            cur = cur.next
            
        m = n - k
        if m < 0:
            return None
        cur = head
        for i in xrange(m):
            cur = cur.next
        return cur
