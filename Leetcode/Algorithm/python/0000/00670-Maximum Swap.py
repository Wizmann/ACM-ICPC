class Solution(object):
    def maximumSwap(self, num):
        ns = map(int, list(str(num)))
        n = len(ns)
        
        maxi, maxi_ptr = -1, 0
        st = 1
        while st < n and ns[st] <= ns[st - 1]:
            st += 1
        for i in xrange(st, n):
            if ns[i] >= maxi:
                maxi = ns[i]
                maxi_ptr = i

        res = num
        for i in xrange(n):
            ns[i], ns[maxi_ptr] = ns[maxi_ptr], ns[i]
            res = max(res, int(''.join(map(str, ns))))
            ns[i], ns[maxi_ptr] = ns[maxi_ptr], ns[i]
        return res
