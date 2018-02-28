class Solution:
    """
    @param num: a non-negative integer N
    @return: the largest number that is less than or equal to N with monotone increasing digits.
    """
    def monotoneDigits(self, num):
        num = map(int, str(num))
        n = len(num)
        
        for i in xrange(n - 1):
            if num[i] > num[i + 1]:
                if num[i] == 0:
                    while num[i] == 0:
                        i -= 1
                        
                if num[i] > 1:
                    num[i] -= 1
                    for j in xrange(i + 1, n):
                        num[j] = 9
                    break
                else:
                    num = [9 for i in xrange(n - 1)]
                    break
        return int(''.join(map(str, num)))
