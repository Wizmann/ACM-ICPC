from collections import defaultdict

class Solution(object):
    def maxSubarrays(self, n, conflictingPairs):
        d = defaultdict(list)
        for (a, b) in conflictingPairs:
            if a > b:
                a, b = b, a
            d[b].append(a)

        ans = 0
        left = [0, 0]
        rem = [0 for i in xrange(n + 1)]
        for i in xrange(1, n + 1):
            for l in d[i]:
                left.append(l)
                for j in xrange(len(left) - 1, 0, -1):
                    if left[j] > left[j - 1]:
                        left[j], left[j - 1] = left[j - 1], left[j]
                left = left[:2]
            ans += i - left[0]
            rem[left[0]] += left[0] - left[1]
        return ans + max(rem)
