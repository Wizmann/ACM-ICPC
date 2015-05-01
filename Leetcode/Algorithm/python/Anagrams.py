class Solution:
    # @param strs, a list of strings
    # @return a list of strings
    def anagrams(self, strs):
        d = {}
        for s in strs:
            ss = ''.join(str(sorted(s)))
            l = d.get(ss, [])
            l.append(s)
            d[ss] = l
        
        ans = []
        for (key, vlist) in d.items():
            if len(vlist) > 1:
                ans += vlist
        return ans
