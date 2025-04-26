class Trie(object):
    def __init__(self):
        self.d = {0: [-1, -1, False]}
        
    def insert(self, s):
        cur = 0
        for c in s:
            u = ord(c) - ord('0')
            if cur not in self.d:
                self.d[cur] = [-1, -1, False]
            if self.d[cur][u] == -1:
                self.d[cur][u] = cur * 2 + 1 + u
            cur = self.d[cur][u]
        self.d[cur] = [-1, -1, True]
    
    def search(self, s):
        cur = 0
        res = ''
        for c in s:
            u = ord(c) - ord('0')
            if self.d[cur][u ^ 1] != -1:
                u ^= 1
            res += str(u)
            cur = self.d[cur][u]
        return int(res, 2)       

class Solution(object):
    def findMaximumXOR(self, nums):
        nums = map(lambda num: '{:032b}'.format(num), nums)
        trie = Trie()
        for num in nums:
            trie.insert(num)
        ans = 0
        for num in nums:
            ans = max(ans, trie.search(num) ^ int(num, 2))
        return ans
