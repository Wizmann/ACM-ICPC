#coding=utf-8
import sys

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53]

cnt = 0
for prime in primes:
    print prime
    sys.stdout.flush()
    s = sys.stdin.readline().strip()
    cnt += (s == 'yes')
    
    if s == 'yes' and prime * prime <= 100:
        print prime * prime
        sys.stdout.flush()
        s = sys.stdin.readline().strip()
        cnt += (s == 'yes')
    
    if cnt >= 2:
        break

if cnt <= 1:
    print 'prime'
else:
    print 'composite'
