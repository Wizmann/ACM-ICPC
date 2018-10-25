MOD = (10 ** 9) + 7

class Solution(object):
    def threeEqualParts(self, A):
        n = len(A)
        ones = sum(A)
        if ones == 0:
            return [0, 2]
        if ones % 3 != 0:
            return [-1, -1]
        block = ones / 3
        
        q = n - 1
        cnt = 0
        h = 0
        step = 0
        while q >= 0 and cnt < block:
            if A[q] == 1:
                cnt += 1
            h = (h + A[q] * pow(2, step, MOD)) % MOD
            q -= 1
            step += 1
        print h
        p = 0
        hh = 0
        while p < n and hh != h:
            hh = ((hh * 2) + A[p]) % MOD
            p += 1
        print hh
        if p == n or hh != h:
            return [-1, -1]
        
        q = p
        hh = 0
        while q < n and hh != h:
            hh = ((hh * 2) + A[q]) % MOD
            q += 1
        print hh
        if hh != h:
            return [-1, -1]
        
        return [p - 1, q]
        
        
