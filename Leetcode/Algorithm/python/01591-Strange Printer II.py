from collections import defaultdict

INF = 10 ** 10

class Solution(object):
    def isPrintable(self, targetGrid):
        d = defaultdict(list)
        minys = {}
        maxys = {}
        minxs = {}
        maxxs = {}
        
        n = len(targetGrid)
        m = len(targetGrid[0])
        
        for i in xrange(n):
            for j in xrange(m):
                cur = targetGrid[i][j]
                minys[cur] = min(i, minys.get(cur, INF))
                maxys[cur] = max(i, maxys.get(cur, -INF))
                minxs[cur] = min(j, minxs.get(cur, INF))
                maxxs[cur] = max(j, maxxs.get(cur, -INF))
                d[cur].append((i, j))
                
        while d:
            nxt = -1
            for key, ps in d.items():
                flag = True
                for i in xrange(minys[key], maxys[key] + 1):
                    for j in xrange(minxs[key], maxxs[key] + 1):
                        if targetGrid[i][j] not in [key, -1]:
                            flag = False
                            break
                if flag:
                    nxt = key
                    break
            if nxt == -1:
                return False
            
            for i in xrange(minys[nxt], maxys[nxt] + 1):
                for j in xrange(minxs[nxt], maxxs[nxt] + 1):
                    targetGrid[i][j] = -1
                    
            for line in targetGrid:
                print line
            print '---'
            del d[nxt]
        
        return True
