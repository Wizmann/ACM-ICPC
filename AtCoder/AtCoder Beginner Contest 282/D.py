#python3
import sys
import threading
from collections import defaultdict, Counter

xrange = range
raw_input = input

def main():
    (n, m) = map(int, raw_input().split())

    g = defaultdict(list)

    for i in xrange(m):
        (a, b) = map(int, raw_input().split())
        g[a].append(b)
        g[b].append(a)

    visited = set()

    def dfs(pre, cur, color, d):
        visited.add(cur)
        if cur in d:
            if d[cur] != color:
                d = {}
                return False
            return True

        d[cur] = color
        color ^= 1
        for nxt in g[cur]:
            if nxt == pre:
                continue
            if not dfs(cur, nxt, color, d):
                return False
        return True

    flag = True
    res = 0
    for i in xrange(1, n + 1):
        if i not in visited:
            d = defaultdict(int)

            if not dfs(-1, i, 0, d):
                flag = False
                break

            cnt = [0, 0]
            for _, value in d.items():
                cnt[value] += 1

            # print cnt
            res += cnt[0] * (n - cnt[0]) + cnt[1] * (n - cnt[1])
        if not flag:
            break
    if flag:
        print((res - m * 2) // 2)
    else:
        print(0)

if __name__ == "__main__":
    sys.setrecursionlimit(2**32//2-1)
    threading.stack_size(1 << 27)
 
    thread = threading.Thread(target=main)
    thread.start()
    thread.join()

'''
^^^^TEST^^^
5 4
4 2
3 1
5 2
3 2
------
2
$$$TEST$$$$$

^^^^TEST^^^
4 3
3 1
3 2
1 2
------
0
$$$TEST$$$$$

^^^^TEST^^^
9 11
4 9
9 1
8 2
8 3
9 2
8 4
6 7
4 6
7 5
4 5
7 8
------
9
$$$TEST$$$$$
'''
