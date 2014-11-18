# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a list node
    # @return a tree node
    def sortedListToBST(self, head):
        n, cur = 0, head
        while cur:
            n += 1
            cur = cur.next
        return self.do_sortedListToBST(n, head)
    
    def do_sortedListToBST(self, n, head):
        if not n:
            return None
        prev, cur = None, head
        for i in xrange(n / 2):
            prev = cur
            cur = cur.next
        next = cur.next
        root = TreeNode(cur.val)
        if prev:
            prev.next = None
        root.left = self.do_sortedListToBST(n / 2, head)
        root.right = self.do_sortedListToBST(n - n / 2 - 1, next)
        return root
