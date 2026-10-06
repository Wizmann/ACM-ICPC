from collections import defaultdict

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isEvenOddTree(self, root):
        queue = [[root], []]
        levels = defaultdict(list)
        p = 0
        level = 0
        while queue[p]:
            # print levels
            q = p ^ 1
            cur = queue[p].pop(0)
            levels[level].append(cur.val)
            if cur.left:
                queue[q].append(cur.left)
            if cur.right:
                queue[q].append(cur.right)
            if not queue[p]:
                p = q
                level += 1
        for i in xrange(level):
            # print levels[i]
            if i % 2 != 0:
                if not self.check_even(levels[i]):
                    return False
            else:
                if not self.check_odd(levels[i]):
                    return False
        return True
    
    def check_even(self, ns):
        if len(set(ns)) != len(ns):
            return False
        if filter(lambda x: x % 2 != 0, ns):
            return False
        if sorted(ns)[::-1] != ns:
            return False
        return True
    
    def check_odd(self, ns):
        if len(set(ns)) != len(ns):
            return False
        if filter(lambda x: x % 2 == 0, ns):
            return False
        if sorted(ns) != ns:
            return False
        return True
