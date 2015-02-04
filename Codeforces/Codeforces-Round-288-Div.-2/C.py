import sys

(m, t, r) = map(int, raw_input().split())
ghosts = map(int, raw_input().split())

# impossible
if t < r:
    print -1
    sys.exit(0)

ans = 0
candles = [-1 for i in xrange(r)]

for ghost in ghosts:
    delay = 0
    for i in xrange(r):
        if candles[i] < ghost:
            candles[i] = ghost + t - 1 - delay
            delay += 1
            ans += 1

print ans
