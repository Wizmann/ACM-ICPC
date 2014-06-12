import sys

sys.stdin = open('input.txt')

n = int(raw_input()) + 1
ns = map(int, raw_input().split())
sns = sorted(ns)

ns = [0] + ns
sns = [0] + sns

for i in xrange(n):
    if not i:
        continue
    ns[i] += ns[i - 1]
    sns[i] += sns[i - 1]
    
q = int(raw_input())
for i in xrange(q):
    (c, a, b) = map(int, raw_input().split())
    a -= 1
    if c == 1:
        print ns[b] - ns[a]
    else:
        print sns[b] - sns[a]
