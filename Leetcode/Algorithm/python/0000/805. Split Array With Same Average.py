class Solution(object):
    def splitArraySameAverage(self, A):
        n = len(A)
        
        if n == 1:
            return False
        
        acc = sum(A)
        ave = 1.0 * sum(A) / n
        
        l, r = A[:n / 2], A[n / 2:]
        
        s = set()

        for i in xrange(1, 1 << len(l)):
            cnt, tot = 0, 0
            for j in xrange(len(l)):
                if i & (1 << j):
                    cnt += 1
                    tot += l[j]
            s.add((cnt, tot))
            
            if cnt * acc == tot * n:
                return True

        for i in xrange(1, 1 << len(r)):
            cnt, tot = 0, 0
            for j in xrange(len(r)):
                if i & (1 << j):
                    cnt += 1
                    tot += r[j]

            if cnt * acc == tot * n:
                return True
            
            for j in xrange(1, len(l) + 1):
                if j + cnt == n:
                    continue
                if acc * (cnt + j) % n != 0:
                    continue
                b = acc * (cnt + j) / n - tot
                if (j, b) in s:
                    return True
        return False
                
            
