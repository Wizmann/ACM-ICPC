class Solution:
    # @return a list of lists of integers
    def combine(self, n, k):
        self.result = []
        self.tmp = []
        self._combine(1, n, k)
        return self.result
        
    def _combine(self, ptr, n, k):
        while ptr <= n:
            self.tmp.append(ptr)
            if len(self.tmp) == k:
                self.result.append(self.tmp[:])
                self.tmp.pop()
            else:
                self._combine(ptr + 1, n, k)
                self.tmp.pop()
            ptr += 1
