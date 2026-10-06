# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def numComponents(self, head, G):
        G = set(G)
        pre = False
        res = 0
        
        while head:
            if head.val in G:
                pre = True
            else:
                if pre == True:
                    res += 1
                pre = False
            head = head.next
        return res + pre
