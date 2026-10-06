INF = 10 ** 10

class Solution(object):
    def minimumSum(self, num):
        num = map(int, str(num))
        mini = INF
        for i in xrange(1 << 4):
            left, right = [], []
            for j in xrange(4):
                if i & (1 << j):
                    left.append(num[j])
                else:
                    right.append(num[j])
            if left and right:
                # print left, right
                a = int(''.join(map(str, sorted(left))))
                b = int(''.join(map(str, sorted(right))))
                mini = min(mini, a + b)
        return mini
