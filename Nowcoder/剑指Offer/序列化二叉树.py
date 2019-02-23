# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import json

class Solution:
    def Serialize(self, root):
        d = {}
        def doSerialize(root, nr):
            if not root:
                return
            d[nr] = root.val
            doSerialize(root.left, nr * 2 + 1)
            doSerialize(root.right, nr * 2 + 2)
        doSerialize(root, 0)
        return json.dumps(d)
    def Deserialize(self, s):
        d = json.loads(s)
        def doDeserialize(nr):
            if str(nr) not in d:
                return None
            root = TreeNode(d[str(nr)])
            root.left = doDeserialize(nr * 2 + 1)
            root.right = doDeserialize(nr * 2 + 2)
            return root
        return doDeserialize(0)
