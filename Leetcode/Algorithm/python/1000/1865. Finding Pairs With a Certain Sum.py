from collections import defaultdict

class FindSumPairs(object):

    def __init__(self, nums1, nums2):
        self.d = defaultdict(int)
        self.nums1 = nums1
        self.nums2 = nums2
        
        for item in nums2:
            self.d[item] += 1

    def add(self, index, val):
        pre = self.nums2[index]
        cur = pre + val
        self.d[pre] -= 1
        self.d[cur] += 1
        self.nums2[index] = cur        

    def count(self, tot):
        res = 0
        for a in self.nums1:
            res += self.d[tot - a]
        return res
        


# Your FindSumPairs object will be instantiated and called as such:
# obj = FindSumPairs(nums1, nums2)
# obj.add(index,val)
# param_2 = obj.count(tot)
