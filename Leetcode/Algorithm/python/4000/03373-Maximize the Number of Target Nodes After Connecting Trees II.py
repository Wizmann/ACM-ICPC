from collections import defaultdict

class Solution(object):
    def maxTargetNodes(self, edges1, edges2):
        self.g1 = defaultdict(list)
        self.g2 = defaultdict(list)
        n = 0
        for (a, b) in edges1:
            self.g1[a].append(b)
            self.g1[b].append(a)
            n = max(n, a, b)
        for (a, b) in edges2:
            self.g2[a].append(b)
            self.g2[b].append(a)

        self.cnt1_odd = defaultdict(int)
        self.cnt1_even = defaultdict(int)
        self.cnt2_odd = defaultdict(int)
        self.cnt2_even = defaultdict(int)
        
        self.dfs1(-1, 0, self.g1, self.cnt1_odd, self.cnt1_even)
        self.dfs1(-1, 0, self.g2, self.cnt2_odd, self.cnt2_even)
        
        self.maxi2_odd = 0
        self.maxi2_even = 0
        self.dfs2(-1, 0, 0, 0)

        self.ans = {}
        self.dfs3(-1, 0, 0, 0)
        return [self.ans[i] for i in xrange(n + 1)]

    def dfs1(self, pre, cur, g, cnt_odd, cnt_even):
        cnt_even[cur] += 1
        for nxt in g[cur]:
            if nxt == pre:
                continue
            delta_odd, delta_even = self.dfs1(cur, nxt, g, cnt_odd, cnt_even)
            cnt_odd[cur] += delta_even
            cnt_even[cur] += delta_odd
        return (cnt_odd[cur], cnt_even[cur])

    def dfs2(self, pre, cur, odd, even):
        odd += self.cnt2_odd[cur]
        even += self.cnt2_even[cur]
        self.maxi2_odd = max(self.maxi2_odd, odd)
        self.maxi2_even = max(self.maxi2_even, even)
        for nxt in self.g2[cur]:
            if nxt == pre:
                continue
            self.dfs2(cur, nxt, even - self.cnt2_odd[nxt], odd - self.cnt2_even[nxt])
        
    def dfs3(self, pre, cur, odd, even):
        odd += self.cnt1_odd[cur]
        even += self.cnt1_even[cur]
        self.ans[cur] = even + self.maxi2_even

        for nxt in self.g1[cur]:
            if nxt == pre:
                continue
            self.dfs3(cur, nxt, even - self.cnt1_odd[nxt], odd - self.cnt1_even[nxt])


