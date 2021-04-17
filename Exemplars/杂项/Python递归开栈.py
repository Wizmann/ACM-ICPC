#codeforces 369C

# 只适用于Python2/3，不适用于pypy2/3

import sys
import threading

from collections import defaultdict

def main():
    n = int(raw_input())

    d = defaultdict(list)

    for i in xrange(n - 1):
        a, b, c = map(int, raw_input().split())
        a -= 1
        b -= 1
        d[a].append((b, c))
        d[b].append((a, c))

    cnt = [0 for i in xrange(n)]

    def dfs1(pre, cur):
        for (nxt, flag) in d[cur]:
            if nxt == pre:
                continue
            cnt[cur] += dfs1(cur, nxt) + (1 if flag == 2 else 0)
        return cnt[cur]

    dfs1(-1, 0)

    st = set()

    def dfs2(pre, cur):
        is_leaf = True
        for (nxt, flag) in d[cur]:
            if nxt == pre:
                continue
            #print nxt, cnt[nxt]
            if cnt[nxt] or flag == 2:
                is_leaf = False
                dfs2(cur, nxt)
        if is_leaf:
            st.add(cur)

    dfs2(-1, 0)

    st = list(st)

    if st == [0]:
        print 0
    else:
        print len(st)
        for item in sorted(st):
            print item + 1,

if __name__ == "__main__":
    sys.setrecursionlimit(2**32//2-1)
    threading.stack_size(1 << 27)
 
    thread = threading.Thread(target=main)
    thread.start()
    thread.join()
