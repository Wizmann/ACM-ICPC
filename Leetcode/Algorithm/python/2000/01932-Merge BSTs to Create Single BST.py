from collections import defaultdict

INF = 10 ** 10

class DisjointSet(object):
    def __init__(self):
        self.father = {}
        
    def find_father(self, x):
        if x not in self.father:
            self.father[x] = x
            return x
        
        if self.father[x] == x:
            return x
        f = self.find_father(self.father[x])
        self.father[x] = f
        return f
    
    def check_union(self, a, b):
        fa = self.find_father(a)
        fb = self.find_father(b)
        return fa == fb
    
    def make_union(self, a, b):
        fa = self.find_father(a)
        fb = self.find_father(b)
        self.father[fb] = fa

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def canMerge(self, trees):
        root_d = {}
        leaf_d = {}
        leaf_id = {}
        n = len(trees)
        leaves = []
        ds = DisjointSet()
        
        for root in trees:
            if root.val in root_d:
                return None
            root_d[root.val] = root
            
            if root.left:
                if root.val == root.left.val:
                    return None
                if root.left.val in leaf_d:
                    return None
                leaf_id[root.left.val] = root.val
                leaf_d[root.left.val] = root.left
                leaves.append(root.left.val)
                
            if root.right:
                if root.val == root.right.val:
                    return None
                if root.right.val in leaf_d:
                    return None
                leaf_id[root.right.val] = root.val
                leaf_d[root.right.val] = root.right
                leaves.append(root.right.val)
        
        for leaf in leaves:
            # print root_d
            if leaf not in root_d:
                continue
            leaf_root = leaf_id[leaf]
            if ds.check_union(leaf_root, root_d[leaf].val):
                continue
            ds.make_union(leaf_root, root_d[leaf].val)
            leaf_d[leaf].left = root_d[leaf].left
            leaf_d[leaf].right = root_d[leaf].right
            del root_d[leaf]
            if len(root_d) == 1:
                break
        if len(root_d) > 1:
            return None
        root = root_d.values()[0]
        
        if self.checkBST(root, -INF, INF):
            return root
        else:
            return None
        
    def checkBST(self, cur, mini, maxi):
        if not cur:
            return True
        if cur.val <= mini or cur.val >= maxi:
            return False
        return self.checkBST(cur.left, mini, cur.val) and \
               self.checkBST(cur.right, cur.val, maxi)
                
            
        
        
