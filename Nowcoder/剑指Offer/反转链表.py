# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # 返回ListNode
    def ReverseList(self, pHead):
        pre, cur = None, pHead
        while cur:
            next, cur.next = cur.next, pre
            pre, cur = cur, next
        return pre
