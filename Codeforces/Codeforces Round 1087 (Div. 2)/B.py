class Node(object):
    def __init__(self, val):
        self.val = val
        self.lt = 0
        self.eq = 1
        self.gt = 0
        self.left = None
        self.right = None


class BSTex(object):
    def __init__(self, ns=None):
        self.root = None
        if ns:
            for x in ns:
                self.insert(x)

    def insert(self, x):
        if self.root is None:
            self.root = Node(x)
            return

        cur = self.root
        while True:
            if x == cur.val:
                cur.eq += 1
                return
            if x < cur.val:
                cur.lt += 1
                if cur.left is None:
                    cur.left = Node(x)
                    return
                cur = cur.left
            else:
                cur.gt += 1
                if cur.right is None:
                    cur.right = Node(x)
                    return
                cur = cur.right

    def remove(self, x):
        # We only remove values that are known to exist in current multiset.
        cur = self.root
        while cur is not None:
            if x == cur.val:
                cur.eq -= 1
                return
            if x < cur.val:
                cur.lt -= 1
                cur = cur.left
            else:
                cur.gt -= 1
                cur = cur.right

    def count_lt(self, x):
        ans = 0
        cur = self.root
        while cur is not None:
            if x <= cur.val:
                cur = cur.left
            else:
                ans += cur.lt + cur.eq
                cur = cur.right
        return ans

    def count_gt(self, x):
        ans = 0
        cur = self.root
        while cur is not None:
            if x >= cur.val:
                cur = cur.right
            else:
                ans += cur.gt + cur.eq
                cur = cur.left
        return ans


def solve(ns):
    bst = BSTex(ns)
    res = []
    for num in ns:
        bst.remove(num)
        gt = bst.count_gt(num)
        lt = bst.count_lt(num)
        res.append(max(gt, lt))
    return res


T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())
    ns = map(int, raw_input().split())
    print(' '.join(map(str, solve(ns))))

'''
^^^^TEST^^^^
6
1
1092
2
105 -105
5
1 2 93 84 2
7
2 9 38 4 7 1 6
10
1 9 20 9 829 3 87 1 283 7
11
9 18 29817 283 3 3928 5726 1942 1000000000 -1000000000 19
---------
0
1 0
4 2 2 1 0
5 4 4 2 2 1 0
8 4 4 3 5 3 2 2 1 0
8 7 7 4 5 3 3 2 2 1 0
$$$$$TEST$$$$$
'''
