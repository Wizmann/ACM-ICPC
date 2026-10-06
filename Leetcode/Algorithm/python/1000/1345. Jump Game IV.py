# https://leetcode.com/problems/jump-game-iv/

from collections import defaultdict

INF = 10 ** 19

class Solution:
    def minJumps(self, arr):
        d = defaultdict(list)
        n = len(arr)
        for i, num in enumerate(arr):
            d[num].append(i)
        dis = [INF for i in range(n)]
        dis[0] = 0
        inq = set([0])
        q = [0]
        s = set([0])
        while q:
            cur = q.pop(0)
            step = dis[cur]
            inq.remove(cur)
            
            nxts = []
            if cur - 1 >= 0 and arr[cur] != arr[cur - 1]:
                nxts.append(cur - 1)
            if cur + 1 < n and arr[cur] != arr[cur + 1]:
                nxts.append(cur + 1)

            if arr[cur] not in s:
                nxts += d[arr[cur]]
                s.add(arr[cur])
            
            for nxt in nxts:
                if dis[nxt] > step + 1:
                    dis[nxt] = step + 1
                    if nxt not in inq:
                        q.append(nxt)
                        inq.add(nxt)
        #print(dis)
        return dis[-1]

