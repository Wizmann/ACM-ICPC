class Solution(object):
    def maximumBeauty(self, flowers, newFlowers, target, full, partial):
        n = len(flowers)
        flowers = map(lambda x: min(x, target), flowers)
        flowers.sort()

        presum = flowers[:]
        for i in xrange(1, n):
            presum[i] += presum[i - 1]

        tot = sum(flowers)

        left, right = tot, 0
        res = 0
        ptr = n

        for i in xrange(n, -1, -1):
            if i < n:
                right += flowers[i]
                left -= flowers[i]
            b = (n - i) * target - right
            ptr = min(ptr, i)
            while ptr > 0 and flowers[ptr - 1] == target:
                ptr -= 1
            if b > newFlowers:
                break
            if ptr > 0:
                while ptr > 0:
                    if newFlowers - b < (flowers[ptr - 1] * ptr - presum[ptr - 1]):
                        ptr -= 1
                    else:
                        break

                assert ptr >= 1
                u = (newFlowers - b + presum[ptr - 1]) / ptr
                u = min(target - 1, u)
                cur = (n - i) * full + partial * u
            else:
                cur = (n - i) * full
            # print i, ptr, cur
            res = max(res, cur)
        return res



'''
^^^^TEST^^^^
[1,3,1,1]
7
6
12
1
-------
14
$$$TEST$$$

^^^^TEST^^^^
[2,4,5,3]
10
5
2
6
-------
30
$$$TEST$$$

^^^^TEST^^^^
[5,5,15,1,9]
36
12
9
2
-------
58
$$$TEST$$$

^^^^TEST^^^^
[100000,100000,100000,100000]
10000000000
100000
100000
100000
-----
400000
$$$TEST$$$

'''
