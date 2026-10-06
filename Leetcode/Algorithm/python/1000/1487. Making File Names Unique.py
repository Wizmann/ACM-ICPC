from collections import defaultdict

class Solution(object):
    def getFolderNames(self, names):
        d = defaultdict(int)
        res = []
        files = set()
        for name in names:
            idx = d[name]
            while True:
                fn = self.getFileName(name, idx)
                if fn in files:
                    idx += 1
                else:
                    break
            d[name] = idx
            
            fn = self.getFileName(name, idx)
            res.append(fn)
            files.add(fn)
        return res      
    def getFileName(self, name, idx):
        if idx == 0:
            return name
        return name + "(%d)" % idx
