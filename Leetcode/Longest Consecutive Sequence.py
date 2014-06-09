class Solution:
    # @param num, a list of integer
    # @return an integer
    def longestConsecutive(self, num):
        s = set(num)
        visited = set()
        ans = 0
        for i in num:
            l = i - 1
            r = i + 1
            if i in visited:
                continue
            visited.add(i)
            v = 1
            while l in s:
                v += 1
                visited.add(l)
                l -= 1
            while r in s:
                v += 1
                visited.add(r)
                r += 1
            ans = max(ans, v)
        return ans
                
