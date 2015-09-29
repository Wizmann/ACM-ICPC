import sys
sys.stdin = open('input.txt')

n = int(raw_input())
ns = map(int, raw_input().split())

s = sum(ns) / 45 * 9

if ns.count(0) != 0:
    print int('5' * s + '0' * ns.count(0))
else:
    print -1
