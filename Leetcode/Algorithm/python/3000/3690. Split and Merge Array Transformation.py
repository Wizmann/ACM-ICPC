# -*- coding: utf-8 -*-
from collections import deque, Counter

class Solution(object):
    def minSplitMerge(self, nums1, nums2):
        uniq = {}
        for i, v in enumerate(sorted(set(nums1))):
            uniq[v] = i
        start = tuple(uniq[v] for v in nums1)
        goal  = tuple(uniq[v] for v in nums2)

        if start == goal:
            return 0

        return self._bfs(start, goal)

    def _neighbors(self, state):
        n = len(state)
        s = state
        for l in xrange(n):
            # r 必须取到 n（开区间），否则“切到末尾”的情况会漏
            for r in xrange(l + 1, n + 1):
                block = s[l:r]
                if r - l == n:
                    # 整段搬移只会得到相同序列，无需处理
                    continue
                rem = s[:l] + s[r:]
                m = len(rem)
                for i in xrange(m + 1):
                    if i == l:
                        # 把段放回原位 -> 无变化，剪掉
                        continue
                    # rem[:i] + block + rem[i:]
                    yield rem[:i] + block + rem[i:]

    def _bfs(self, start, goal):
        q = deque([start])
        dist = {start: 0}
        seen = set([start])

        while q:
            cur = q.popleft()
            d = dist[cur]

            # 扩展相邻状态
            for nxt in self._neighbors(cur):
                if nxt in seen:
                    continue
                if nxt == goal:
                    return d + 1
                seen.add(nxt)
                dist[nxt] = d + 1
                q.append(nxt)

        return -1
