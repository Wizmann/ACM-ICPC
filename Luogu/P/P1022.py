#python3
import re
from collections import defaultdict

EPS = 1e-4

def parse(expr):
    expr = expr.strip()
    if expr[0] == '-':
        expr = '0' + expr

    items = re.split('([+-])', expr)
    res = defaultdict(int)

    pre = 1
    for item in items:
        if item in '+-':
            if item == '+':
                pre = 1
            elif item == '-':
                pre = -1
            continue

        if item.isdigit():
            v = pre * int(item)
            res[1] += v
        else:
            if item[0].isdigit():
                v = int(''.join(filter(lambda x: x.isdigit(), item)))
                x = ''.join(filter(lambda x: not x.isdigit(), item))

                res[x] += pre * v
            else:
                res[item] += pre
    return res

def merge(left, right):
    left[1] -= right[1]
    if 1 in right:
        del right[1]
    if right.keys():
        key = list(right.keys())[0]
        left[key] -= right[key]
    return left

expr = input()

left, right = expr.split('=')

left = parse(left)
right = parse(right)

# print(left, right)

res = merge(left, right)

num = res[1]
del res[1]

key = list(res.keys())[0]
value = list(res.values())[0]


ans = -num / value
if abs(ans) < EPS:
    ans = 0

print('%s=%.3f' % (key, ans))

'''
^^^^^^^^TEST^^^^^
6a-5+1=2-2a
-------------
a=0.750
$$$$$TEST$$$

^^^^^^^^TEST^^^^^
4+3x=8
-------------
x=1.333
$$$$$TEST$$$

^^^^^^^^TEST^^^^^
-5+12y=0
-------------
y=0.417
$$$$$TEST$$$

^^^^^^^^TEST^^^^^
0=-5+12y
-------------
y=0.417
$$$$$TEST$$$
'''

