N = 100010
sieve = [True for i in xrange(N)]

i = 2
while i * i < N:
    if sieve[i]:
        j = 2
        while i * j < N:
            sieve[i * j] = False
            j += 1
    i += 1
    
primes = []
for i in xrange(2, N):
    if sieve[i]:
        primes.append(i)

class DisjointSet(object):
    def __init__(self):
        self.d = {}
        
    def find_father(self, x):
        if self.d.get(x, x) == x:
            return x
        ff = self.find_father(self.d[x])
        self.d[x] = ff
        return ff
    
    def same_union(self, a, b):
        fa = self.find_father(a)
        fb = self.find_father(b)
        return fa == fb
    
    def make_union(self, a, b):
        fa = self.find_father(a)
        fb = self.find_father(b)
        self.d[fa] = fb
        
from collections import defaultdict

class Solution(object):
    def gcdSort(self, nums):
        n = len(nums)
        ds = DisjointSet()
        for num in nums:
            factors = []
            u = num
            for p in primes:
                if p * p > u:
                    break
                if u % p == 0:
                    factors.append(p)
                while u % p == 0:
                    u /= p

            if u != 1:
                factors.append(u)

            for f in factors:
                ds.make_union(num, f)
        d = defaultdict(list)
        for i, num in enumerate(nums):
            f = ds.find_father(num)
            d[f].append((num, i))
        
        nums = [-1 for i in xrange(n)]
        for key, values in d.items():
            vs, ps = map(list, zip(*values))
            vs.sort()
            ps.sort()
            # print vs, ps
            for num, pos in zip(vs, ps):
                nums[pos] = num
        # print nums
        return all(nums[i] <= nums[i+1] for i in xrange(n - 1))
