from collections import defaultdict

class Solution(object):
    def removeSubfolders(self, folder):
        tree = defaultdict(dict)
        for path in folder:
            p = filter(lambda x: x, path.split('/'))            
            cur = tree
            m = len(p)
            for i in xrange(m):
                if p[i] not in cur:
                    cur[p[i]] = {}
                cur = cur[p[i]]
            cur[''] = {}
        res = []
        
        def dfs(tree, path):
            print path
            if '' in tree:
                res.append('/' + '/'.join(path))
                return
            for key, value in tree.items():
                path.append(key)
                dfs(value, path)
                path.pop()
        dfs(tree, [])
        return res
