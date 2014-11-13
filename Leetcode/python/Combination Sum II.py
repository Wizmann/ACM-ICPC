class Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def combinationSum2(self, candidates, target):
        self.result = []
        self.tmp = []
        candidates.sort()
        self._combinationSum2(0, candidates, target)
        return self.result
        
    def _combinationSum2(self, ptr, candidates, target):
        prev = sum(self.tmp)
        while ptr < len(candidates):
            s = prev + candidates[ptr]
            if s > target:
                break
            self.tmp.append(candidates[ptr])
            if s == target:
                self.result.append(self.tmp[:])
                self.tmp.pop()
                break
            else:
                self._combinationSum2(ptr + 1, candidates, target)
                self.tmp.pop()
            ptr += 1
                
            while ptr >= 0 and \
                    ptr < len(candidates) and \
                    candidates[ptr] == candidates[ptr - 1]:
                ptr += 1
        
