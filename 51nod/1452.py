import sys
sys.stdin = open('input.txt')

s = raw_input()
pos = [-1]
for i, c in enumerate(s):
    if c == '*':
        pos.append(i)
pos.append(len(s))
num = len(pos)

ans = 0
for i in xrange(num):
    for j in xrange(i + 1, num):
        a = pos[i] + 1
        b = pos[j]
        e = s[:a] + '(' + s[a:b] + ')' + s[b:]
        print e
        ans = max(ans, eval(e))
print ans
