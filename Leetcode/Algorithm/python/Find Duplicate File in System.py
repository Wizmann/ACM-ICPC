from collections import defaultdict

class Solution(object):
    def findDuplicate(self, paths):
        d = defaultdict(list)
        for s in paths:
            for (path, content) in self.parse(s):
                d[content].append(path)
        return filter(lambda x: len(x) > 1, d.values())
        
    def parse(self, s):
        s = s.split()
        root = s[0]
        items = s[1:]
        for item in items:
            item = item.replace('(', ' ').replace(')', ' ').strip().split()
            path, content = item
            yield (root + '/' + path, content)
