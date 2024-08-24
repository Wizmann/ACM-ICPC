#python3

n = int(input())
ns = list(map(int, input().split()))

cnt = 0
for i in range(n):
    cur = ns[i]

    cnt += (cur // 5) * 3
    cur %= 5

    while cur:
        cnt += 1
        if cnt % 3 == 0:
            cur = max(0, cur - 3)
        else:
            cur = max(0, cur - 1)

    assert(cur == 0)

print(cnt)

'''
^^^^^TEST^^^^
2
6 2
---------------
6
$$$$TEST$$$$

^^^^^TEST^^^^
3
6 2 2
---------------
8
$$$$TEST$$$$

^^^^^TEST^^^^
9
1 12 123 1234 12345 123456 1234567 12345678 123456789
---------------
82304529
$$$$TEST$$$$

^^^^^TEST^^^^
5
1000000000 1000000000 1000000000 1000000000 1000000000
---------------
3000000000
$$$$TEST$$$$
'''
