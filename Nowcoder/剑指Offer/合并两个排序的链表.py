# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

INF = 10 ** 10

class Solution:
    # 返回合并后列表
    def Merge(self, pHead1, pHead2):
        dummyHead = ListNode(-1)
        cur = dummyHead
        while pHead1 or pHead2:
            v1 = pHead1.val if pHead1 else INF
            v2 = pHead2.val if pHead2 else INF
            if v1 < v2:
                cur.next = ListNode(v1)
                cur, pHead1 = cur.next, pHead1.next
            else:
                cur.next = ListNode(v2)
                cur, pHead2 = cur.next, pHead2.next
        return dummyHead.next
