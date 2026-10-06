def count(i):
    s = map(int, str(i))
    cnt = 0
    for i in xrange(1, len(s) - 1):
        if s[i - 1] < s[i] and s[i] > s[i + 1]:
            cnt += 1
        elif s[i - 1] > s[i] and s[i] < s[i + 1]:
            cnt += 1
    return cnt

tot = []
for i in xrange(123456):
    if i < 100:
        tot.append(0)
    else:
        tot.append(count(i))
    if i - 1 >= 0:
        tot[i] += tot[i - 1]

class Solution(object):
    def totalWaviness(self, num1, num2):
        return tot[num2] - tot[num1 - 1]
