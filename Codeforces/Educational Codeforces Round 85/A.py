
def solve(records):
    A, B = 0, 0
    for (a, b) in records:
        if a < A:
            return False
        if b < B:
            return False
        db = b - B
        da = a - A

        if db > da:
            return False
        A, B = a, b
    return True

T = int(raw_input())

for case_ in xrange(T):
    n = int(raw_input())

    records = []
    for i in xrange(n):
        (a, b) = map(int, raw_input().split())
        records.append((a, b))

    print 'YES' if solve(records) else 'NO'
