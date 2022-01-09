class Solution:
    def combinationSum(self, candidates, target):
        candidates.sort()
        self.tmp = []
        self.result = []
        self._combinationSum(0, candidates, target)
        return self.result
    
    def _combinationSum(self, ptr, candidates, target):
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
                self._combinationSum(ptr, candidates, target)
                ptr += 1
                self.tmp.pop()
