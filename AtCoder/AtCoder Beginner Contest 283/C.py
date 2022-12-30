S = raw_input()

n = len(S)
i = 0
cnt = 0
while i < n:
    if S[i] in '123456789':
        cnt += 1
        i += 1
    elif i + 1 < n and S[i + 1] == '0':
        cnt += 1
        i += 2
    else:
        cnt += 1
        i += 1
print cnt

'''

^^^TEST^^^^^
40004
-------------
4
$$$TEST$$$

^^^TEST^^^^^
1355506027
-------------
10
$$$TEST$$$

^^^TEST^^^^^
10888869450418352160768000001
-------------
27
$$$TEST$$$


'''
