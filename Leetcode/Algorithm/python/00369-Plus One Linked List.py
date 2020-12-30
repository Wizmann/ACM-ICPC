# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def plusOne(self, head):
        if not head:
            return None
        
        dummy_head = ListNode(0)
        dummy_head.next = head
        
        self.dfs(dummy_head)
        
        if dummy_head.val == 0:
            return dummy_head.next
        else:
            return dummy_head
        
    def dfs(self, cur):
        if cur.next == None:
            cur.val += 1
            g = cur.val / 10
            cur.val %= 10
            return g
        
        g = self.dfs(cur.next)
        cur.val += g
        g = cur.val / 10
        cur.val %= 10
        
        return g
        
        
