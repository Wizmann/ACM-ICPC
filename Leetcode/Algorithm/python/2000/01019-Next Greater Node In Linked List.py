# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def nextLargerNodes(self, head):
        self.st = []
        self.res = []
        self.dfs(head)
        return self.res
        
    
    def dfs(self, cur):
        if cur == None:
            return []
        idx = len(self.res)
        self.res.append(0)
        maxi = self.dfs(cur.next)
        
        while maxi and cur.val >= maxi[-1]:
            maxi.pop()
            
        if maxi:
            self.res[idx] = maxi[-1]
        maxi.append(cur.val)
        return maxi
        
