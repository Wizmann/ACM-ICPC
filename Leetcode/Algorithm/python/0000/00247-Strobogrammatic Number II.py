class Solution(object):
    def findStrobogrammatic(self, n):
        d = {
            '0': '0',
            '1': '1',
            '6': '9',
            '8': '8',
            '9': '6'
        }
        
        res = []
        
        def dfs(l, r, buf):
            if l > r:
                res.append(''.join(buf))
            elif l == r:
                for key in '018':
                    buf[l] = key
                    res.append(''.join(buf))
            else:
                for (key, value) in d.items():
                    if l == 0 and key == '0':
                        continue
                    buf[l], buf[r] = key, value
                    dfs(l + 1, r - 1, buf)
        
        dfs(0, n - 1, ['' for i in xrange(n)])
        return res
