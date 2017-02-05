# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.d = {}
    
    def findFrequentTreeSum(self, root):
        self._findFrequentTreeSum(root)
        if not self.d:
            return []
            
        max_freq = max(
            map(
                lambda (x, y): y, 
                self.d.items()
            )
        )
        return list(
            map(
                lambda (x, y): x, 
                filter(
                    lambda (x, y): y == max_freq, 
                    self.d.items()
                )
            )
        )
    
    def _findFrequentTreeSum(self, root):
        if root == None:
            return 0
        
        l = self._findFrequentTreeSum(root.left)
        r = self._findFrequentTreeSum(root.right)
        sum = l + r + root.val
        self.d[sum] = self.d.get(sum, 0) + 1
        return sum
        
