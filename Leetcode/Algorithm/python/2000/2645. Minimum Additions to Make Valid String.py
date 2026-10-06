class Solution(object):
    def addMinimum(self, word):
        ptr = 0
        cnt = 0
        for c in word:
            while True:
                if c == 'abc'[ptr]:
                    ptr = (ptr + 1) % 3
                    break
                else:
                    ptr = (ptr + 1) % 3
                    cnt += 1
        while ptr != 0:
            cnt += 1
            ptr = (ptr + 1) % 3
        return cnt
                
