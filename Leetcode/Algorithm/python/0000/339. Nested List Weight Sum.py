class Solution(object):
    def depthSum(self, nestedList, depth=1):
        res = 0
        for item in nestedList:
            if item.isInteger():
                res += depth * item.getInteger()
            else:
                res += self.depthSum(item.getList(), depth + 1)
        return res
