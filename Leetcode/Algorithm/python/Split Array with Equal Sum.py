from collections import defaultdict

class Solution(object):
    def splitArray(self, nums):
        n = len(nums)
        
        d1 = self.calc(nums)
        d2 = self.calc(nums[::-1])

        for i in xrange(n):
            a, b = i, n - 1 - i
            #print i, d1[a], d2[b]
            if d1[a] & d2[b]:
                return True
        return False
        
        
    def calc(self, nums):
        n = len(nums)
        prefix = [0]
        for item in nums[:-1]:
            prefix.append(prefix[-1] + item)
        d1 = defaultdict(list)
        for i, pre in enumerate(prefix):
            d1[pre].append(i)
        #print prefix
        d2 = defaultdict(set)
        for i in xrange(1, n):
            other = filter(lambda x: x > i + 1, d1.get(prefix[i] * 2 + nums[i], []))
            #print i, other
            for item in other:
                d2[item].add(prefix[i])
        return d2
