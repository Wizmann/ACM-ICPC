class Solution(object):
    def brokenCalc(self, X, Y):
        if X >= Y:
            return X - Y
        else:
            cnt = 0
            XX = X
            while X < Y:
                X *= 2
                cnt += 1
            step = (X - Y) / (2 ** cnt)
            X = XX - step
            cnt = 0
            while X < Y:
                X *= 2
                cnt += 1
            return '{:b}'.format(X - Y).count('1') + cnt + step
