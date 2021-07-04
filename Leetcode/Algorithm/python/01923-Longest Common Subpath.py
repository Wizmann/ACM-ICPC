LENGTH = (10 ** 5) + 123
MOD = 0xdeadbeefcafebabe
pows = [1]
PRIME = 23456789

for i in xrange(1, LENGTH):
    pows.append(pows[i - 1] * PRIME % MOD)

class Solution(object):
    def longestCommonSubpath(self, n, paths):
        l, r = 0, min(map(len, paths))
        while l <= r:
            m = (l + r) / 2
            if self.check(paths, m):
                l = m + 1
            else:
                r = m - 1
        return r
    
    def check(self, paths, mid):
        n = len(paths)
        st = set()

        for path in paths[:1]:
            h = 0
            for i in xrange(mid):
                h = h * PRIME % MOD
                h += path[i]
            for i in xrange(mid, len(path)):
                st.add(h)
                h = h * PRIME % MOD
                h += path[i]
                h = ((h - path[i - mid] * pows[mid] % MOD) % MOD + MOD) % MOD
            st.add(h)

        # print mid, st
        
        for path in paths[1:]:
            h = 0
            st2 = set()
            for i in xrange(mid):
                h = h * PRIME % MOD
                h += path[i]
            for i in xrange(mid, len(path)):
                st2.add(h)
                h = h * PRIME % MOD
                h += path[i]
                h = ((h - path[i - mid] * pows[mid] % MOD) % MOD + MOD) % MOD
            st2.add(h)
            st &= st2
            # print '>>', mid, st2, st
        
            if not st:
                break
        # print '>>>', mid, st
        return len(st)
        
        
        

assert Solution().longestCommonSubpath(
    5,
    [[0,1,2,3,4],[2,3,4],[4,0,1,2,3]]) == 2

assert Solution().longestCommonSubpath(
        5,
        [[0,1,2,3,4],
       [4,3,2,1,0]]) == 1
