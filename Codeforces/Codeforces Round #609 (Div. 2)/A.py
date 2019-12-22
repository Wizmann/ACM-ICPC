def solve(n):
    if n == 1:
        return 9, 8
    else:
        return 3 * n, 2 * n
 
def test(n):
    a, b = solve(n)
    assert a - b == n
    assert a % n == 0 and b % n == 0
 
for i in xrange(1, 10):
    test(i)
 
n = int(raw_input())
a, b = solve(n)
print a, b
