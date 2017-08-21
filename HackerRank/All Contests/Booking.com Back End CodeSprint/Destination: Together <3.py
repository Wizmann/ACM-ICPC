# Enter your code here. Read input from STDIN. Print output to STDOUT

def C(a, b):
    res = 1
    for i in xrange(a):
        res *= (b - i)
        res /= i + 1
    return res

def F(x):
    res = 1
    for i in xrange(x):
        res *= i + 1
    return res

(n, m, c) = map(int, raw_input().split())


print F(n + m - c - 1)
