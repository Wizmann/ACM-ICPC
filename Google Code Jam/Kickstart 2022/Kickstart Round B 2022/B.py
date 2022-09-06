#python3
import math
INF = 10 ** 100

def check_palindrome(x):
    return str(x) == str(x)[::-1]

T = int(input())

for case_ in range(T):
    n = int(input())

    i = 1
    cnt = 0
    while i * i <= n:
        if n % i == 0:
            cnt += check_palindrome(i)
            if n != i * i:
                cnt += check_palindrome(n // i)
        i += 1

    print('Case #%d: %d' % (case_ + 1, cnt))


'''
^^^^^TEST^^^
4
6
10
144
242
----------------
Case #1: 4
Case #2: 3
Case #3: 7
Case #4: 6
$$$$TEST$$$

'''


