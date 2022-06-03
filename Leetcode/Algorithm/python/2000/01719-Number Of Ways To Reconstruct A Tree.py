from collections import defaultdict, Counter

class Solution(object):
    def checkWays(self, pairs):
        self.g = defaultdict(set)
        st = set()
        for (a, b) in pairs:
            self.g[a].add(b)
            self.g[b].add(a)
            st.add(a)
            st.add(b)
        self.dp = {}
        res = self.dfs(st)
        return min(2, res)
    
    def dfs(self, st):
        if len(st) <= 1:
            return 1
        # print st

        n = len(st)
        d = defaultdict(int)
        maxi = 0
        maxi_key = -1
        maxi_cnt = 0
        
        for num in st:
            self.g[num] &= st

        nxts = sorted(st, key=lambda x: len(self.g[x]), reverse=True)

        root = nxts[0]
        # print root
        if len(self.g[root]) != n - 1:
            return 0

        cnt = 0
        for nxt in nxts:
            if len(self.g[nxt]) == n - 1:
                cnt += 1
            if cnt >= 2:
                break

        pre = n - 1
        res = 1
        for nxt in nxts[1:]:
            if nxt not in st:
                continue
            if root not in self.g[nxt]:
                res = 0
                break
            sub = self.g[nxt] ^ set([nxt, root])
            assert root not in sub
            assert nxt in sub
            st ^= sub
            res *= self.dfs(sub)
            # print st, sub, res, cnt

        return res * cnt
        

assert Solution().checkWays([[3,4],[2,3],[4,5],[2,4],[2,5],[1,5],[1,4]]) == 0
assert Solution().checkWays([[1,5],[1,3],[2,3],[2,4],[3,5],[3,4]]) == 2
assert Solution().checkWays([[1,2],[2,3]]) == 1
assert Solution().checkWays([[1,2],[2,3],[2,4],[1,5]]) == 0
assert Solution().checkWays([[2,3],[1,3],[1,4],[1,2],[4,5],[2,4],[1,5],[3,5],[3,4]]) == 2
assert Solution().checkWays([[5,7],[11,12],[2,9],[8,10],[1,4],[3,6]]) == 0
assert Solution().checkWays([[1,2],[2,3],[1,3]]) == 2
