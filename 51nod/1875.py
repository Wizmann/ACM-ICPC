class Solution1(object):
    def solve(self, n):
        e = 1
        while True:
            ns = range(1, 2 * n + 1)
            p = 0
            for i in xrange(n):
                num = len(ns)
                p = (p + e - 1) % num
                del ns[p]
            if set(ns) == set(range(1, n + 1)):
                break
            e += 1
        return e

#for i in xrange(14):
#    print Solution1().solve(i)

ans = [
1,
2,
7,
5,
30,
169,
441,
1872,
7632,
1740,
93313,
459901,
1358657,
2504881]

if __name__ == '__main__':
    while True:
        n = int(raw_input())
        if n:
            print ans[n]
        else:
            break



