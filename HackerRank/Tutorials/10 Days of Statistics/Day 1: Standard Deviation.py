import math

n = int(raw_input())
ns = map(int, raw_input().split())

ave = 1.0 * sum(ns) / n
print math.sqrt(sum(map(lambda x: abs(x - ave) ** 2, ns)) / n)
