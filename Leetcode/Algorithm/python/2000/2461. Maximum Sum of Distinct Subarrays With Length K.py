INF = 10 ** 100

class Multiset(object):
    def __init__(self):
        self.d = {}
        self.cnt = 0
        
    def insert(self, item):
        if item not in self.d:
            self.d[item] = 0
        self.d[item] += 1
        self.cnt += 1
    
    def remove(self, item):
        if item not in self.d:
            return 0
        self.d[item] -= 1
        res = self.d[item]
        if not self.d[item]:
            del self.d[item]
        self.cnt -= 1
        return res
    
    def contains(self, item):
        return item in self.d
    
    def size(self):
        return self.cnt
    
    def distinct(self):
        return len(self.d)

class Solution(object):
    def maximumSubarraySum(self, nums, k):
        n = len(nums)
        st = Multiset()
        tot = 0
        res = 0
        for i in xrange(k):
            st.insert(nums[i])
            tot += nums[i]
        
        for i in xrange(k, n + 1):
            if st.distinct() == k:
                res = max(res, tot)
            if i == n:
                break
            tot -= nums[i - k]
            tot += nums[i]
            st.remove(nums[i - k])
            st.insert(nums[i])
        return res
        
