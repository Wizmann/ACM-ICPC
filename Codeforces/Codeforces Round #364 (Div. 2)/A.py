n = int(input())
ns = sorted(enumerate(map(int, input().split())), key=lambda x: x[1])

for i in range(n // 2):
    print(ns[i][0] + 1, ns[n - i - 1][0] + 1)

