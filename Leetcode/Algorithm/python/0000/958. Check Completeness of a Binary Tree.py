# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isCompleteTree(self, root):
        return self.solve([root], 1)
    
    def solve(self, level, num):
        #print map(lambda node: None if not node else node.val, level)
        while level and level[-1] == None:
            level.pop()
            
        l = []
        for node in level:
            if not node:
                return False
            l.append(node.left)
            l.append(node.right)
        
        if len(level) != num:
            return not any(l)
        elif len(level) == num and not l:
            return True
        
        return self.solve(l, num * 2)
