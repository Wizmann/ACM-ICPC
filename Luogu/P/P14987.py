#python3

from itertools import permutations


T = int(input())

for case_ in range(T):
    ns = list(map(int, input().split()))
    ns.sort()

    for perm in permutations(ns):
        a, b, c, d = perm
        if a + b == c + d and a + c == b + d:
            print("Yes")
            break
    else:
        print("No")

'''
^^^^^TEST^^^^
2
0 0 0 0
0 1 2 3
---------
Yes
No
$$$$TEST$$$$
'''




