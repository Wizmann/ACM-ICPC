class Solution(object):
    def mostVisited(self, n, rounds):
        cnt = [0 for i in xrange(n)]
        m = len(rounds)
        p = 1
        rounds = map(lambda x: x - 1, rounds)
        cur = rounds[0]
        while p < m:
            print cur, p
            cnt[cur] += 1
            if cur == rounds[p]:
                p += 1
            cur = (cur + 1) % n
        maxi = max(cnt)
        res = []
        for i in xrange(n):
            if cnt[i] == maxi:
                res.append(i + 1)
        return res
            
