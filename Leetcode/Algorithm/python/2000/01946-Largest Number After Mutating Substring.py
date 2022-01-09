class Solution(object):
    def maximumNumber(self, num, change):
        num = map(int, num)
        n = len(num)
        flag = False
        for i in xrange(n):
            if change[num[i]] > num[i]:
                num[i] = change[num[i]]
                flag = True
            elif change[num[i]] == num[i]:
                if flag:
                    num[i] = change[num[i]]
            else:
                if flag:
                    break
        return ''.join(map(str, num))
