import sys

sys.stdin = open("input.txt")

(n, k) = map(int, raw_input().split())

res = 0

for i in xrange(n):
    s = map(int, raw_input())
    st = set()
    for item in s:
        if item > k:
            pass
        else:
            st.add(item)
    else:
        if len(st) == k + 1:
            res += 1
            #print s, 'yes'

print res
