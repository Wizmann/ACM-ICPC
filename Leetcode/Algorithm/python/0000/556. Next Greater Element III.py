class Solution(object):
    def nextGreaterElement(self, num):
        num = map(int, str(num))
        n = len(num)
        
        for i in xrange(n - 2, -1, -1):
            if num[i] < num[i + 1]:
                for j in xrange(n - 1, i, -1):
                    if num[j] > num[i]:
                        num[i], num[j] = num[j], num[i]
                        num[i + 1:] = num[i + 1:][::-1]
                        break
                break
        else:
            return -1

        ans = int(''.join(map(str, num)))
        if ans > 0x3fffffff:
            return -1
        return ans
        
