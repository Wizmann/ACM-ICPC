n = int(raw_input())
tree = [
    map(int, raw_input().split())
    for i in xrange(n)
]

for i in xrange(n - 1, -1, -1):
    for j in xrange(i):
        a = tree[i][j]
        b = tree[i][j + 1]
        tree[i - 1][j] += max(a, b)
        
print tree[0][0]
