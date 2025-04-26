# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapNodes(self, head, k):
        self.node1 = None
        self.node2 = None
        self.dfs(head, k, 1, None)

        self.node1.val, self.node2.val = \
                self.node2.val, self.node1.val
        return head


    def dfs(self, cur, k, leftcnt, node1):
        if cur == None:
            return 1 # right most node

        if leftcnt == k:
            self.node1 = cur # left node to swap

        rightcnt = self.dfs(cur.next, k, leftcnt + 1, node1)

        if rightcnt == k:
            self.node2 = cur

        return rightcnt + 1

