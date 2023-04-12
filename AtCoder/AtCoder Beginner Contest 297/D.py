def solve(a, b):
    if a == b:
        return 0
    a, b = min(a, b), max(a, b)

    if b % a == 0:
        return b / a - 1
    return b / a + solve(b % a, a)

a, b = map(int, raw_input().split())

print solve(a, b)


'''
^^^^^^TEST^^^^^
3 8
------------
4
$$$$$TEST$$$

^^^^^^TEST^^^^^
1234567890 1234567890
------------
0
$$$$$TEST$$$

^^^^^^TEST^^^^^
1597 987
------------
15
$$$$$TEST$$$

'''
