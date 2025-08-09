INF = 10 ** 100

def merge_count(arr):
    if len(arr) <= 1:
        return arr, 0
    mid = len(arr) // 2
    left, left_count = merge_count(arr[:mid])
    right, right_count = merge_count(arr[mid:])
    
    merged, count = merge(left, right)
    return merged, left_count + right_count + count

def merge(left, right):
    merged = []
    count = 0
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            j += 1
            count += len(left) - i
    merged.extend(left[i:])
    merged.extend(right[j:])
    return merged, count

class Solution(object):
    def minSwaps(self, nums):
        evens = []
        odds = []
        self.n = len(nums)
        for i, num in enumerate(nums):
            if num % 2 == 0:
                evens.append(i)
            else:
                odds.append(i)

        res = min(self.solve(evens, odds), self.solve(odds, evens))
        if res >= INF:
            return -1
        return res

    def solve(self, ns1, ns2):
        if not len(ns1) in [len(ns2), len(ns2) + 1]:
            return INF
        ns = [0 for i in xrange(self.n)]
        
        for i, num in enumerate(ns1):
            ns[num] = i * 2
            
        for i, num in enumerate(ns2):
            ns[num] = i * 2 + 1
        _, inv = merge_count(ns)
        return inv
