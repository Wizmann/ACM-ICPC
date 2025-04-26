from collections import defaultdict

class Solution(object):
    def watchedVideosByFriends(self, watchedVideos, friends, id, level):
        fs = self.bfs(id, friends, level)
        d = defaultdict(int)
        
        for f in fs:
            for v in watchedVideos[f]:
                d[v] += 1
        
        return map(lambda (movie, cnt): movie, sorted(d.items(), key=lambda (movie, cnt): (cnt, movie)))
        
    def bfs(self, cur, friends, level):
        q = [cur]
        d = {cur: 0}
        res = []
        while q:
            cur = q.pop()
            l = d[cur]
            if l == level:
                res.append(cur)
                continue
            for f in friends[cur]:
                if f in d:
                    continue
                d[f] = l + 1
                q.append(f)
        return res
        
