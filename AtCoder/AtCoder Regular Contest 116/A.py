T = int(raw_input())

def solve(n):
    twos = 0
    while n % 2 == 0:
        twos += 1
        n /= 2
    if twos == 1:
        return 'Same'
    elif twos == 0:
        return 'Odd'
    else:
        return 'Even'

for case_ in xrange(T):
    n = int(raw_input())

    print solve(n)

'''
^^^^TEST^^^
3
2
998244353
1000000000000000000
----
Same
Odd
Even
$$$TEST$$$
'''


