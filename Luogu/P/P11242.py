#python3
from collections import Counter
n = int(input())

ns = list(map(int, input().split()))

print(max(ns) + len(ns) - 1)


'''
^^^^TEST^^^^
4
2 3 4 5
---------
8
$$$$TEST$$$

^^^^TEST^^^^
7
6 6 7 8 4 2 4
---------
14
$$$$TEST$$$
'''
