import sys
import random

class IInteractive(object):
    def init(self):
        pass

    def refresh(self):
        pass

    def query(self, nums):
        pass


class LocalInteractive(IInteractive):
    def __init__(self, T, n):
        random.seed(0)
        self.T = T
        self.n = n
        self.Q = 300

    def init(self):
        return [self.T, self.n, self.Q]

    def refresh(self):
        self.cnt = 0
        self.nums = range(1, self.n + 1)
        random.shuffle(self.nums)

    def query(self, nums):
        self.cnt += 1
        assert self.cnt < self.Q
        if len(nums) == 3:
            values = map(lambda x: self.nums[x - 1], nums)
            # print self.nums, sorted(zip(values, nums))
            return sorted(zip(values, nums))[1][1]
        else:
            res1 = [-1 for i in xrange(self.n)]
            res2 = [-1 for i in xrange(self.n)]
            for i, num in enumerate(nums):
                res1[num - 1] = i + 1
                res2[num - 1] = self.n - i
            assert self.nums == res1 or self.nums == res2
            return 1

class JudgeInteractive(IInteractive):
    def __init__(self):
        pass

    def init(self):
        T, n, Q = map(int, raw_input().split())
        return [T, n, Q]

    def refresh(self):
        pass

    def query(self, nums):
        print ' '.join(map(str, nums))
        sys.stdout.flush()
        return int(raw_input())


class Solution(object):
    def __init__(self, n, Q, interactive):
        self.n = n
        self.Q = Q
        self.interactive = interactive

    def solve(self):
        n = self.n
        self.nums = [-1 for i in xrange(n)]

        self.solve_by_minmax(0, n, range(1, n + 1))

        # print self.nums, self.interactive.nums #TODO remove it
        assert -1 not in self.nums
        # print self.interactive.query(self.nums)
        assert self.interactive.query(self.nums) == 1

    def solve_by_minmax(self, l, r, bag, **kwargs):
        if l == r:
            return
        if l + 1 == r:
            assert len(bag) == 1
            self.nums[l] = bag[0]
            return

        random.shuffle(bag)
        pivot1, pivot2 = bag[:2]
        left_bag, middle_bag, right_bag = [], [], []
        for num in bag:
            if num == pivot1 or num == pivot2:
                continue
            v = self.interactive.query([pivot1, pivot2, num])
            if v == pivot1:
                left_bag.append(num)
            elif v == num:
                middle_bag.append(num)
            else:
                right_bag.append(num)

        if 'mini' in kwargs:
            pre = kwargs['mini']
            v = self.interactive.query([pre, pivot1, pivot2])
            if v == pivot2:
                pivot1, pivot2 = pivot2, pivot1
                left_bag, right_bag = right_bag, left_bag
        elif 'maxi' in kwargs:
            pre = kwargs['maxi']
            v = self.interactive.query([pre, pivot1, pivot2])
            if v == pivot1:
                pivot1, pivot2 = pivot2, pivot1
                left_bag, right_bag = right_bag, left_bag

        self.nums[l + len(left_bag)] = pivot1
        self.nums[l + len(left_bag) + len(middle_bag) + 1] = pivot2
        # print pre, pivot, left_bag, right_bag
        # print pivot1, pivot2, self.nums, len(left_bag), len(middle_bag), len(right_bag)
        self.solve_by_minmax(l, l + len(left_bag), left_bag, maxi=pivot1)
        self.solve_by_minmax(l + len(left_bag) + 1, l + len(left_bag) + 1 + len(middle_bag), middle_bag, mini=pivot1, maxi=pivot2)
        self.solve_by_minmax(l + len(left_bag) + 2 + len(middle_bag), r, right_bag, mini=pivot2)


def solve(interactive):
    T, n, Q = interactive.init()
    for case_ in xrange(T):
        interactive.refresh();
        S = Solution(n, Q, interactive)
        S.solve()


solve(LocalInteractive(100, 4))
solve(LocalInteractive(100, 50))
solve(JudgeInteractive())

