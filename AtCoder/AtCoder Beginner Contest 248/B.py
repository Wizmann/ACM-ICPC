(a, b, k) = map(int, raw_input().split())

step = 0
while a < b:
    a *= k
    step += 1
print step


'''
^^^^^TEST^^^
1 4 2
------
2
$$$TEST$$$


^^^^^TEST^^^
7 7 10
------
0
$$$TEST$$$

^^^^^TEST^^^
31 415926 5
------
6
$$$TEST$$$
'''
