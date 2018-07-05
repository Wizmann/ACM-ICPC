'''$$$
[Description]
Given a positive integer N, it is possible to represent N as the sum of several positive or negative powers of 2 (± 2k for some k). 

For example 7 can be represented as 2^2 + 2^1 + 2^0 and 2^3 - 2^0.

Your task is to find the representation which contains the minimum powers of 2.

[Tags]
dfs, implementation, dp

[Difficulty]
2.5

[Url]
http://hihocoder.com/problemset/problem/1410
$$$'''

def bruteforce(x):
    u = len('{:b}'.format(x))
    ans = u
    for i in xrange(3 ** (u + 1)):
        v = i
        cnt = 0
        t = 0
        for j in xrange(u + 1):
            y = v % 3
            v /= 3
            if y != 0:
                cnt += 1

            if y == 0:
                continue
            t += (2 ** j) * (1 if y == 2 else -1)
        if t == x:
            ans = min(ans, cnt)
    return ans

d = {}
def do_solve(x):
    while x and x[0] == '0':
        x = x[1:]

    while x and x[-1] == '0':
        x = x[:-1]

    if not x:
        return 0
    if x in d:
        return d[x]

    if x.count('0') == 0:
        return min(len(x), 2)

    res = x.count('0') + 2
    for i in xrange(len(x)):
        if x[i] == '0':
            res = min(res, do_solve(x[:i]) + do_solve(x[i + 1:]))
    d[x] = res
    return res

def solve(x):
    u = '{:b}'.format(x)
    return do_solve(u)

assert solve(0b110110) == 3
assert solve(0b10) == 1
assert bruteforce(0b10) == 1
assert solve(0b1111010111) == 4
assert solve(0b111) == 2
assert solve(0b101) == 2
assert solve(0b100) == 1
assert solve(0b1111110111) == 3

for i in xrange(1, 20):
    #print '{:b}'.format(i), solve(i), bruteforce(i)
    assert solve(i) == bruteforce(i)

if __name__ == '__main__':
    print solve(int(raw_input()))

