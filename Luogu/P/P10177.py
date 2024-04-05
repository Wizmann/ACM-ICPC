#python3
INF = 10 ** 100

n = int(input())
ns = list(map(int, input().split()))

ns.sort()

maxi = -INF
for i in range(1, n):
    maxi = max(maxi, ns[i - 1] - ns[i])

print(maxi)

'''

^^^^TEST^^^^
2
1 1
---------
0
$$$TEST$$$$

^^^^TEST^^^^
4
2 4 1 3
---------
-1
$$$TEST$$$$

'''



