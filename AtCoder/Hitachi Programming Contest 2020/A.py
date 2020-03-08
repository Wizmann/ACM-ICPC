# https://atcoder.jp/contests/hitachi2020/tasks/hitachi2020_a

s = raw_input()
n = len(s)
if n % 2 != 0:
    print 'No'
else:
    m = n / 2
    pattern = 'hi' * m
    print 'Yes' if pattern == s else 'No'
