# https://leetcode.com/problems/linked-list-in-binary-tree/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubPath(self, head: ListNode, root: TreeNode) -> bool:
        pattern = []
        while head:
            pattern.append(head.val)
            head = head.next
        nxt = self.getKmpNext(pattern)
        return self.dfs(root, pattern, nxt, 0)
    
    def getKmpNext(self, pattern):
        n = len(pattern)
        nxt = [-1 for i in range(n + 1)]
        
        pre, suf = -1, 0
        while pre < n and suf < n:
            if pre == -1 or pattern[pre] == pattern[suf]:
                pre += 1
                suf += 1
                nxt[suf] = pre
            else:
                pre = nxt[pre]
        return nxt
    
    def dfs(self, cur, pattern, nxt, p):
        if p == len(pattern):
            return True
        if not cur:
            return False
        while p < len(pattern):
            if p == -1 or cur.val == pattern[p]:
                p += 1
                b1 = lambda: self.dfs(cur.left, pattern, nxt, p)
                b2 = lambda: self.dfs(cur.right, pattern, nxt, p)
                return b1() or b2()
            else:
                p = nxt[p]
        return False
        
