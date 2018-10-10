# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class CBTInserter(object):

    def __init__(self, root):
        self.nodes = []
        
        self.bfs(root)
        
    def bfs(self, root):
        q = [root]
        while q:
            cur = q.pop(0)
            self.nodes.append(cur)
            
            if cur.left:
                q.append(cur.left)
            if cur.right:
                q.append(cur.right)

    def insert(self, v):
        node = TreeNode(v)
        self.nodes.append(node)
        idx = len(self.nodes) - 1
        p = (idx - 1) / 2
        
        if not self.nodes[p].left:
            self.nodes[p].left = node
        elif not self.nodes[p].right:
            self.nodes[p].right = node
        else:
            assert False
            
        return self.nodes[p].val
        

    def get_root(self):
        return self.nodes[0]
        


# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(v)
# param_2 = obj.get_root()
