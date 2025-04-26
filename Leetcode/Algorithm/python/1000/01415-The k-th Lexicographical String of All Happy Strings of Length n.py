class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        res = []
        for i in range(n):
            rem = n - i - 1
            # print(i, k)
            for j in range(3):
                if res and j == res[-1]:
                    continue
                maxi = 2 ** rem
                if maxi >= k:
                    res.append(j)
                    break
                k -= maxi
            else:
                res = []
                break
        resstr = ''
        for num in res:
            resstr += 'abc'[num]
        return resstr            
