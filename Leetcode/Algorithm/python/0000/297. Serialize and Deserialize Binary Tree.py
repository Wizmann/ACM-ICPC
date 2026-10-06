import cPickle
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def serialize(self, root):
        if not root:
            return ''
        st = []
        res = [ [0, -1, -1] ]
        d = {None: -1, id(root): 0}
        while root or st:
            if root:
                idx = d[id(root)]
                if root.left:
                    d[id(root.left)] = len(res)
                    res.append([0, -1, -1])
                if root.right:
                    d[id(root.right)] = len(res)
                    res.append([0, -1, -1])
                res[idx] = [
                    root.val,
                    d[id(root.left)] if root.left else -1,
                    d[id(root.right)] if root.right else -1
                ]
                st.append(root)
                root = root.left
            else:
                root = st.pop()
                root = root.right
        return cPickle.dumps(res)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        def to_node(item):
            val, left_idx, right_idx = item
            node = TreeNode(val)
            node.left = left_idx
            node.right = right_idx
            return node
        if not data:
            return None
        data = map(to_node, cPickle.loads(data))
        
        for item in data:
            item.left  = data[item.left]  if item.left  != -1 else None
            item.right = data[item.right] if item.right != -1 else None
        return data[0]

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
