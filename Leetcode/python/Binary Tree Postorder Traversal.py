# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def postorderTraversal(self, root):
        if not root:
            return []
        st, res = [root], []
        prev = None
        
        while st:
            cur = st[-1]
            if (not cur.left and not cur.right) or \
                    (prev and (prev == cur.left or prev == cur.right)):
                res.append(cur)
                st.pop()
                prev = cur
            else:
                if cur.right:
                    st.append(cur.right)
                if cur.left:
                    st.append(cur.left)
        return map(lambda x: x.val, res)
