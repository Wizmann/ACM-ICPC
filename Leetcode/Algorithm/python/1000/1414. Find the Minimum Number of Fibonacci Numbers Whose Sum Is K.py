MAXI = 10 ** 9

fibs = [1, 1]
while fibs[-1] < MAXI:
    fibs.append(fibs[-1] + fibs[-2])

class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        ptr = len(fibs) - 1
        res = 0
        while k:
            # print(k, ptr, fibs[ptr])
            if k >= fibs[ptr]:
                res += 1
                k -= fibs[ptr]
            ptr -= 1
        return res
                
        
