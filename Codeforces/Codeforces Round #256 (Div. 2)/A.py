a = sum(map(int, raw_input().split()))
b = sum(map(int, raw_input().split()))
n = int(raw_input())

na = (a + 4) / 5
nb = (b + 9) / 10

if na + nb <= n:
    print "YES"
else:
    print "NO"
