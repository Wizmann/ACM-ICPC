from collections import Counter

class Solution(object):
    def recoverArray(self, n, sums):
        if 0 not in sums:
            return []
        if n == 1:
            return [ sum(sums) ]
        sums.sort()

        delta = sums[1] - sums[0]

        left, right = [], []
        c = Counter(sums)
        
        for num in sums:
            if not c[num]:
                continue
            left.append(num)
            c[num] -= 1
            u = num + delta
            # print num, u, c
            assert c[u]
            c[u] -= 1
            right.append(u)
        left = self.recoverArray(n - 1, left)
        if left:
            return [delta] + left
        right = self.recoverArray(n - 1, right)
        if right:
            return [-delta] + right
        return []
