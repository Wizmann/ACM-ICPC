class Solution:
    # @return a list of lists of length 3, [[val1,val2,val3]]
    def threeSum(self, num):
        num.sort()
        n = len(num)
        res = []
        for i in xrange(n):
            if i - 1 >= 0 and num[i - 1] == num[i]:
                continue
            if num[i] > 0: # Crucial
                continue
            p, q = i + 1, n - 1
            while p < q:
                if p - 1 > i and num[p - 1] == num[p]:
                    p += 1
                    continue
                if q + 1 < n and num[q + 1] == num[q]:
                    q -= 1
                    continue
                s = num[i] + num[p] + num[q]
                if s == 0:
                    res.append(map(lambda x: num[x], [i, p, q]))
                    p += 1
                    q -= 1
                elif s > 0:
                    q -= 1
                else:
                    p += 1
        return res
