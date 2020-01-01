class Solution(object):
    def canReach(self, arr, start):
        n = len(arr)
        visit = [0 for i in xrange(n)]
        
        q = [start]
        while q:
            cur = q.pop(0)
            if arr[cur] == 0:
                return True
            if visit[cur]:
                continue
            visit[cur] = 1
            
            for i in [arr[cur], -arr[cur]]:
                nxt = cur + i
                if nxt < 0 or nxt >= n:
                    continue
                if not visit[nxt]:
                    q.append(nxt)
        return False
