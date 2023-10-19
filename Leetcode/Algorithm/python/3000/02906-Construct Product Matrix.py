BUCKET = 100
MOD = 12345

class Solution(object):
    def constructProductMatrix(self, grid):
        n = len(grid)
        m = len(grid[0])
        buckets = [1 for i in xrange((n * m + BUCKET - 1) / BUCKET)]
        idx = 0

        for i in xrange(n):
            for j in xrange(m):
                b = idx / BUCKET
                grid[i][j] %= MOD
                buckets[b] = buckets[b] * grid[i][j] % MOD
                idx += 1

        pre = -1
        idx = 0
        prod = 1
        res = [ [0 for j in xrange(m)] for i in xrange(n) ]
        for i in xrange(n):
            for j in xrange(m):
                b = idx / BUCKET
                if b != pre:
                    pre = b
                    prod = 1
                    for k, p in enumerate(buckets):
                        if k != b:
                            prod = prod * p % MOD
                            if prod == 0:
                                break
                cur = 1
                left, right = b * BUCKET, min(n * m, (b + 1) * BUCKET)
                # print left, right
                for k in xrange(left, right):
                    if k != i * m + j:
                        cur = cur * grid[k / m][k % m] % MOD
                        if cur == 0:
                            break
                # print cur, prod
                res[i][j] = cur * prod % MOD
                idx += 1
        return res

