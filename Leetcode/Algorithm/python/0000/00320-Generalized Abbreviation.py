class Solution(object):
    def generateAbbreviations(self, word):
        self.res = []
        self.buffer = []
        self.dfs(word, 0)
        return self.res
    
    def dfs(self, word, cur):
        if cur == len(word):
            self.res.append(''.join(self.buffer))
            return
        m = len(word) - cur
        for i in xrange(0, m + 1):
            if i == 0:
                self.buffer.append(word[cur])
                self.dfs(word, cur + 1)
                self.buffer.pop()
            elif not self.buffer or (self.buffer and not self.buffer[-1].isdigit()):
                self.buffer.append(str(i))
                self.dfs(word, cur + i)
                self.buffer.pop()
