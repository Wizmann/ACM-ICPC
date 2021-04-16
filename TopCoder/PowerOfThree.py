class PowerOfThree(object):
    def ableToGet(self, x, y):
        xs = self.to_ternary(x)
        ys = self.to_ternary(y)

        for i in xrange(max(len(xs), len(ys))):
            xb = xs[i] if i < len(xs) else 0
            yb = ys[i] if i < len(ys) else 0
            if abs(xb) + abs(yb) != 1:
                return 'Impossible'
        return 'Possible'

    def to_ternary(self, num):
        ternary = []
        s = 1 if num > 0 else -1
        num_ = abs(num)
        while num_:
            ternary.append(num_ % 3)
            num_ /= 3

        idx = 0
        while idx < len(ternary):
            if ternary[idx] >= 3:
                if idx + 1 == len(ternary):
                    ternary.append(0)
                ternary[idx + 1] += ternary[idx] / 3
                ternary[idx] %= 3

            if ternary[idx] == 2:
                ternary[idx] = -1
                if idx + 1 == len(ternary):
                    ternary.append(0)
                ternary[idx + 1] += 1
            idx += 1

        ternary = map(lambda x: x * s, ternary)
        # print num, ternary
        return ternary

assert PowerOfThree().ableToGet(0, 2) == 'Possible'
assert PowerOfThree().ableToGet(-6890, 18252) == 'Possible'
assert PowerOfThree().ableToGet(1000000000, -1000000000) == 'Impossible'
assert PowerOfThree().ableToGet(1, 9) == 'Impossible'
