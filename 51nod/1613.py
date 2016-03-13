#!/usr/bin/python

def min_odd(a, b):
    x = (a + b - 1) / b
    while x % 2 == 0:
        x += 1
    return x
    
def min_even(a, b):
    x = (a + b - 1) / b
    while x % 2 != 0:
        x += 1
    return x

(n, k) = map(int, raw_input().split())

if n % 2 == 1:
    if k % 2 == 0:
        print -1
    else:
        print min_odd(n, k)
else:
    if k % 2 == 0:
        if n / 2 < k:
            print 3
        else:
            print (n + k - 1) / k
    else:
        if n / 2 < k:
            print min_even(n, (n - k))
        else:
            print min_even(n, k)
