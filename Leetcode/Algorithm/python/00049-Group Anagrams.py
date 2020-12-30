from itertools import groupby

class Solution(object):
    def groupAnagrams(self, strs):
        strkey = lambda s: ''.join(sorted(s))
        return [list(g) for (_, g) in groupby(sorted(strs, key=strkey), strkey)]
        
