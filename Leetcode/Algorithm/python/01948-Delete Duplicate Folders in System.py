from collections import OrderedDict, defaultdict

class Solution(object):
    def deleteDuplicateFolder(self, paths):
        paths.sort()
        
        d = OrderedDict()
        
        for path in paths:
            cur = d
            for node in path:
                if node not in cur:
                    cur[node] = OrderedDict()
                cur = cur[node]
        self.d2 = defaultdict(int)
        self.dfs1(d)
        self.ans = []
        self.dfs2(d, [])
        # print self.ans
        self.ans.sort()
        return self.ans
        
    def dfs1(self, cur):
        h = []
        for key, value in cur.items():
            h1 = self.dfs1(value)
            h1 = "(%s)[%s]" % (key, h1)
            # print key, h1
            h.append(h1)
        # print h
        h = "|".join(h)
        cur["hash"] = h
        self.d2[h] += 1
        return h
    
    def dfs2(self, cur, path):
        if cur['hash'] and self.d2[cur['hash']] > 1:
            return
        if path:
            self.ans.append(path[:])
        for key, value in cur.items():
            if key == 'hash':
                continue
            path.append(key)
            self.dfs2(value, path)
            path.pop()
                

# print Solution().deleteDuplicateFolder([["a"],["c"],["d"],["a","b"],["c","b"],["d","a"]])
