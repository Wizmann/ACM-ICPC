# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class FindElements(object):
    def __init__(self, root):
        self.root = root

    def find(self, target):
        path = []
        while target:
            path.append(target)
            target = (target - 1) / 2
        path.append(0)
        path = path[::-1]
        print path
        return self.dfs(self.root, path)
    
    def dfs(self, root, path):
        if not root:
            return False
        if len(path) == 1:
            return True
        if path[1] == path[0] * 2 + 1:
            return self.dfs(root.left, path[1:])
        else:
            return self.dfs(root.right, path[1:])


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
