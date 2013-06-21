# coding=utf-8
# 3771049	 May 26, 2013 1:38:32 PM	Wizmann	 A - Strange Addition	 Python 2	Accepted	 62 ms	 0 KB
n = int(raw_input())
l = set(map(int, raw_input().split()))
h = [0 if i not in l else 1 for i in xrange(120)]

ans = []

if h[0]:
    ans.append(0)
if h[100]:
    ans.append(100)

one_digit, two_digit = False, False

for i in xrange(1, 10):
    if(h[i]):
        one_digit = True
        ans.append(i)
        break

for i in xrange(10, 100, 10):
    if(h[i]):
        two_digit = True
        ans.append(i)
        break

if not one_digit and not two_digit:
    for i in xrange(1, 100, 1):
        if h[i]:
            ans.append(i)
            break

print len(ans)
print ' '.join(map(str, ans))
