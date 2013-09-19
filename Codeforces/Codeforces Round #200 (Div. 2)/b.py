#coding=utf-8

(a, b, c) = map(int, raw_input().split())

x = a + b - c
y = b - a + c
z = a - b + c


if x < 0 or y < 0 or z < 0 or x % 2 or y % 2 or z % 2:
    print "Impossible"
else:
    print x/2, y/2, z/2
